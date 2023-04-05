#include <libmm/gtk/application.hxx>
#include <libmm/gtk/box.hxx>
#include <libmm/gtk/button.hxx>
#include <libmm/gtk/label.hxx>
#include <libmm/gtk/window.hxx>

class AppWindow
    : public gtk::Window
{
public:
    AppWindow();

private:
    void on_button_clicked();

    gtk::Label* m_label;
};

AppWindow::AppWindow()
    : m_label (nullptr)
{
    auto vbox = gtk::make_managed<gtk::Box>(gtk::Orientation::VERTICAL, 5);
    set_child(*vbox);

    auto button = gtk::make_managed<gtk::Button>("Delete Label");
    vbox->append(*button);

    //m_label = gtk::make_managed<gtk::Label>("test");
    m_label = new gtk::Label("test");
    g_warning("m_label -> ref_count: %d\n", G_OBJECT(m_label->gobj())->ref_count);
    vbox->append(*m_label);
    g_warning("m_label -> ref_count: %d\n", G_OBJECT(m_label->gobj())->ref_count);

    button->signal_clicked().connect( sigc::mem_fun(*this, &AppWindow::on_button_clicked));
}

void AppWindow::on_button_clicked()
{
  if(m_label)
  {
    g_warning("AppWindow::on_button_clicked(): label refcount=%d", G_OBJECT(m_label->gobj())->ref_count);
    delete m_label;
    m_label = nullptr;
  }
}

int main(int argc, char *argv[])
{
  auto app = gtk::Application::create();
  return app->make_window_and_run<AppWindow>(argc, argv);
}
