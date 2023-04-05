#include <libmm/gtk/mm-gtk.hxx>

class MyWindow : public gtk::Window
{
public:
  MyWindow();
private:
  gtk::Button b;
  gtk::Box vbox;
};

MyWindow::MyWindow() :
  b("hello"),
  vbox(gtk::Orientation::VERTICAL)
{
  set_child(vbox);
  b.set_expand(true);
  vbox.append(b);
}

int main(int argc, char* argv[])
{
  auto app = gtk::Application::create();
  return app->make_window_and_run<MyWindow>(argc, argv);
}
