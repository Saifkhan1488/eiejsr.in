#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WLineEdit.h>
#include <Wt/WTemplate.h>

class BusinessApp : public Wt::WApplication {
public:
    BusinessApp(const Wt::WEnvironment& env);

private:
    void showContactForm();
    void handleSubmit();
    Wt::WLineEdit *nameInput_, *emailInput_, *messageInput_;
};

BusinessApp::BusinessApp(const Wt::WEnvironment& env)
    : Wt::WApplication(env) {
    
    setTitle("Professional Business Website");

    root()->addWidget(std::make_unique<Wt::WText>("<h1>Welcome to Our Business</h1>"));
    root()->addWidget(std::make_unique<Wt::WText>("We offer top-notch services for your needs."));
    root()->addWidget(std::make_unique<Wt::WBreak>());

    auto contactButton = root()->addWidget(std::make_unique<Wt::WPushButton>("Contact Us"));
    contactButton->clicked().connect(this, &BusinessApp::showContactForm);
}

void BusinessApp::showContactForm() {
    root()->clear();
    root()->addWidget(std::make_unique<Wt::WText>("<h2>Contact Form</h2>"));

    root()->addWidget(std::make_unique<Wt::WText>("Name: "));
    nameInput_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    root()->addWidget(std::make_unique<Wt::WBreak>());

    root()->addWidget(std::make_unique<Wt::WText>("Email: "));
    emailInput_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    root()->addWidget(std::make_unique<Wt::WBreak>());

    root()->addWidget(std::make_unique<Wt::WText>("Message: "));
    messageInput_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    root()->addWidget(std::make_unique<Wt::WBreak>());

    auto submit = root()->addWidget(std::make_unique<Wt::WPushButton>("Submit"));
    submit->clicked().connect(this, &BusinessApp::handleSubmit);
}

void BusinessApp::handleSubmit() {
    root()->clear();
    root()->addWidget(std::make_unique<Wt::WText>(
        "<h2>Thank You, " + nameInput_->text() + "!</h2>"));
    root()->addWidget(std::make_unique<Wt::WText>(
        "<p>We will contact you at: " + emailInput_->text() + "</p>"));
}

Wt::WApplication *createApp(const Wt::WEnvironment& env) {
    return new BusinessApp(env);
}

int main(int argc, char **argv) {
    return Wt::WRun(argc, argv, &createApp);
}
