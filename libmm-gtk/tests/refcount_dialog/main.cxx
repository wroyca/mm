#include <libmm/gtk/mm-gtk.hxx>
#include <iostream>

// gtk::Dialog is deprecated since 4.10.
// A class that derives from gtk::Window can act as a dialog.
class MyDialog : public gtk::Window
{
public:
  MyDialog()
  : m_ButtonBox(gtk::Orientation::HORIZONTAL),
    m_ButtonOK("OK")
  {
    set_child(m_ButtonBox);
    m_ButtonBox.append(m_ButtonOK);
    m_ButtonBox.set_halign(gtk::Align::END);
  }
  gtk::Button& get_button_ok()
  {
    return m_ButtonOK;
  }
protected:
  gtk::Box m_ButtonBox;
  gtk::Button m_ButtonOK;
};

class MyWindow : public gtk::Window
{
public:
  MyWindow();

  void on_button_clicked();
  void on_dialog_response();

protected:
  gtk::Button m_Button;
  std::unique_ptr<MyDialog> m_Dialog;
};

MyWindow::MyWindow()
: m_Button("Show Dialog")
{
  set_size_request(150, 100);

  m_Button.signal_clicked().connect( sigc::mem_fun(*this, &MyWindow::on_button_clicked) );
  m_Button.set_expand(true);
  set_child(m_Button);
}

void MyWindow::on_button_clicked()
{
  m_Dialog.reset(nullptr);
  std::cout << "before list_toplevels 1" << std::endl;
  std::vector<gtk::Window*> toplevelwindows = list_toplevels();
  std::cout << "after list_toplevels" << std::endl;
  std::cout << "toplevelwindows.size = " << toplevelwindows.size() << std::endl;

  m_Dialog.reset(new MyDialog);
  m_Dialog->set_transient_for(*this);
  m_Dialog->set_modal();
  m_Dialog->set_hide_on_close();
  m_Dialog->get_button_ok().signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_dialog_response));
  m_Dialog->signal_hide().connect(sigc::mem_fun(*this, &MyWindow::on_dialog_response));
  m_Dialog->set_visible(true);
  std::cout << "After m_Dialog->set_visible(true)" << std::endl;
}

void MyWindow::on_dialog_response()
{
  if (m_Dialog->is_visible())
    m_Dialog->set_visible(false);
  else
  {
    std::cout << "before list_toplevels 2" << std::endl;
    std::vector<gtk::Window*> toplevelwindows = list_toplevels();
    std::cout << "after list_toplevels" << std::endl;
    std::cout << "toplevelwindows.size = " << toplevelwindows.size() << std::endl;
  }
}

int main(int argc, char* argv[])
{
  auto app = gtk::Application::create();
  return app->make_window_and_run<MyWindow>(argc, argv);
}
