#include <libmm/gtk/mm-gtk.hxx>

class MyButton : public gtk::Button
{
public:
    MyButton();
    ~MyButton() override;
};

MyButton::MyButton()
: gtk::Button("Ok", true)
{ }

MyButton::~MyButton()
{
    g_warning("MyButtom::~MyButton()");
}

class ExampleWindow : public gtk::Window
{
public:
    ExampleWindow();
    ~ExampleWindow() override;

protected:

    MyButton* m_button;
};

ExampleWindow::ExampleWindow()
{
    set_default_size(150, 150);

    m_button = gtk::make_managed<MyButton>();
    set_child(*m_button);
}

ExampleWindow::~ExampleWindow()
{
  g_warning("ExampleWindow::~ExampleWindow()");
}


int main(int argc, char* argv[])
{
  auto app = gtk::Application::create();
  return app->make_window_and_run<ExampleWindow>(argc, argv);
}
