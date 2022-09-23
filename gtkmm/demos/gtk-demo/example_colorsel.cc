 /* Color Chooser
 *
 * Gtk::ColorChooserDialog lets the user choose a color.
 *
 */

#include <gtkmm.h>

class Example_ColorSel : public Gtk::Window
{
public:
  Example_ColorSel();
  ~Example_ColorSel() override;

protected:
  //Signal handlers:
  void on_button_clicked();
  void on_dialog_response(int response_id);

  //Drawing function:
  void on_drawing_area_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);

  //Member widgets:
  Gtk::Box m_VBox;
  Gtk::Frame m_Frame;
  Gtk::DrawingArea m_DrawingArea;
  Gtk::Button m_Button;
  Gdk::RGBA m_Color;
  std::unique_ptr<Gtk::ColorChooserDialog> m_pDialog;
};

//Called by DemoWindow;
Gtk::Window* do_colorsel()
{
  return new Example_ColorSel();
}

Example_ColorSel::Example_ColorSel()
: m_VBox(Gtk::Orientation::VERTICAL, 8),
  m_Button("_Change the above color", true)
{
  set_title("Color Chooser");
  set_resizable(false);

  m_VBox.set_margin(12);
  set_child(m_VBox);

  // Create the color swatch area
  m_Frame.set_expand(true);
  m_VBox.append(m_Frame);

  // set a fixed size
  m_DrawingArea.set_content_width(200);
  m_DrawingArea.set_content_height(200);

  // set the color
  m_Color.set_rgba(0, 0, 1, 1);
  m_DrawingArea.set_draw_func(sigc::mem_fun(*this, &Example_ColorSel::on_drawing_area_draw));

  m_Frame.set_child(m_DrawingArea);

  m_Button.set_halign(Gtk::Align::END);
  m_Button.set_valign(Gtk::Align::CENTER);

  m_VBox.append(m_Button);

  m_Button.signal_clicked().connect(sigc::mem_fun(*this, &Example_ColorSel::on_button_clicked));
}

Example_ColorSel::~Example_ColorSel()
{
}

void Example_ColorSel::on_button_clicked()
{
  if (!m_pDialog)
  {
    m_pDialog.reset(new Gtk::ColorChooserDialog("Changing color"));
    m_pDialog->set_transient_for(*this);
    m_pDialog->set_hide_on_close(true);
    m_pDialog->set_modal(true);
    m_pDialog->signal_response().connect(
      sigc::mem_fun(*this, &Example_ColorSel::on_dialog_response));
  }
  m_pDialog->set_rgba(m_Color);
  m_pDialog->show();
}

void Example_ColorSel::on_dialog_response(int response_id)
{
  if (response_id == Gtk::ResponseType::OK)
  {
    m_Color = m_pDialog->get_rgba();
    m_DrawingArea.queue_draw();
  }
  m_pDialog->hide();
}

void Example_ColorSel::on_drawing_area_draw(const Cairo::RefPtr<Cairo::Context>& cr, int, int)
{
  Gdk::Cairo::set_source_rgba(cr, m_Color);
  cr->paint();
}
