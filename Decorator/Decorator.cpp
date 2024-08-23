#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};


class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};


class Reversed : public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(std::string& data)  const {
        for (auto it = data.rbegin(); it != data.rend(); ++it)
        {
            std::cout << *it;
        }

        // std::reverse(data.begin(), data.end());
        // std::cout << data;
    }
};


class Link : public DecoratedText {
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    void render(const std::string& ref, const std::string& data)  const {
        std::cout << "<a href=" + ref + ">";
        text_->render(data);
        std::cout << "</a>";
    }
};


class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

int main() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");

    std::cout << std::endl;

    auto text_par = new Paragraph(new Text());
    text_par->render("Hello world");

    std::cout << std::endl;

    auto text_rev = new Reversed(new Text());
    std::string tempText = "Hello world";
    text_rev->render(tempText);

    std::cout << std::endl;

    auto text_link = new Link(new Text());
    text_link->render("netology.ru", "Hello world");
}