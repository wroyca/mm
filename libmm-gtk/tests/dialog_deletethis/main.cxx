#include <libmm/gtk/mm-gtk.hxx>
#include <iostream>

glib::RefPtr<gtk::Application> app;

//This is _not_ a good example of coding with gtkmm.
class Dlg : public sigc::trackable
{
  public:
    Dlg()
    {
      // gtk::Dialog is deprecated since 4.10.
      // A class that derives from gtk::Window can act as a dialog.
      dlg_ = new gtk::Window();
      dlg_->set_title("Test Dialog");
      dlg_->set_hide_on_close();
      auto vBox = gtk::make_managed<gtk::Box>(gtk::Orientation::VERTICAL);
      dlg_->set_child(*vBox);
      auto btn = gtk::make_managed<gtk::Button>("ClickMe");
      btn->signal_clicked().connect(sigc::mem_fun(*this, &Dlg::on_button_clicked));
      btn->set_expand(true);
      vBox->append(*btn);
      vBox->append(*gtk::make_managed<gtk::Separator>(gtk::Orientation::HORIZONTAL));
      auto hBox = gtk::make_managed<gtk::Box>(gtk::Orientation::HORIZONTAL);
      hBox->set_halign(gtk::Align::END);
      vBox->append(*hBox);
      btn = gtk::make_managed<gtk::Button>("OK");
      hBox->append(*btn);
      btn->signal_clicked().connect(sigc::mem_fun(*this, &Dlg::on_response));
      dlg_->signal_hide().connect(sigc::mem_fun(*this, &Dlg::on_response));
      dlg_->set_visible(true);
    }

    ~Dlg()
    {
      delete dlg_;
    }

    void on_button_clicked()
    {
      std::cout << "button clicked" << std::endl;
    }

    void on_response()
    {
      delete this; //This is _not_ a good example of coding with gtkmm.
      app->quit();
    }

  private:
    gtk::Window* dlg_;
};

int main (int argc, char** argv)
{
  app = gtk::Application::create();
  app->register_application();

  new Dlg(); //Not a gtk::Window - it creates one in its constructor.

  app->hold();
  return app->run(argc, argv);
}
