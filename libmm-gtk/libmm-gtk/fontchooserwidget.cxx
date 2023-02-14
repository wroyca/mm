

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/fontchooserwidget.hxx>
#include <libmm-gtk/fontchooserwidget_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkFontChooserWidget* object, const bool take_copy) -> Gtk::FontChooserWidget*
  {
    return dynamic_cast<Gtk::FontChooserWidget*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FontChooserWidget_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FontChooserWidget_Class::class_init_function;

      register_derived_type (gtk_font_chooser_widget_get_type ());

      FontChooser::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FontChooserWidget_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FontChooserWidget_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new FontChooserWidget ((GtkFontChooserWidget*) o));
  }

  FontChooserWidget::FontChooserWidget (
      const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  FontChooserWidget::FontChooserWidget (GtkFontChooserWidget* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  FontChooserWidget::FontChooserWidget (FontChooserWidget&& src) noexcept
    : Widget (std::move (src)),
      FontChooser (std::move (src))
  {
  }

  auto
  FontChooserWidget::operator= (FontChooserWidget&& src) noexcept -> FontChooserWidget&
  {
    Widget::operator= (std::move (src));
    FontChooser::operator= (std::move (src));
    return *this;
  }

  FontChooserWidget::~FontChooserWidget () noexcept
  {
    destroy_ ();
  }

  FontChooserWidget::CppClassType FontChooserWidget::fontchooserwidget_class_;

  auto
  FontChooserWidget::get_type () -> GType
  {
    return fontchooserwidget_class_.init ().get_type ();
  }

  auto
  FontChooserWidget::get_base_type () -> GType
  {
    return gtk_font_chooser_widget_get_type ();
  }

  FontChooserWidget::FontChooserWidget ()
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (fontchooserwidget_class_.init ()))
  {
  }

} // namespace Gtk
