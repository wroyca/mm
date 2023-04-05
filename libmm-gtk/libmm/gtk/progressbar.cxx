// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/progressbar.hxx>
#include <libmm/gtk/progressbar_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>
#include <libmm/gtk/adjustment.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkProgressBar* object, bool take_copy) -> gtk::ProgressBar*
  {
    return dynamic_cast<gtk::ProgressBar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ProgressBar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ProgressBar_Class::class_init_function;

      register_derived_type (gtk_progress_bar_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ProgressBar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ProgressBar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ProgressBar ((GtkProgressBar*) (o)));
  }

  ProgressBar::ProgressBar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ProgressBar::ProgressBar (GtkProgressBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ProgressBar::ProgressBar (ProgressBar&& src) noexcept
    : gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  ProgressBar::operator= (ProgressBar&& src) noexcept -> ProgressBar&
  {
    gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  ProgressBar::~ProgressBar () noexcept
  {
    destroy_ ();
  }

  ProgressBar::CppClassType ProgressBar::progressbar_class_;

  auto
  ProgressBar::get_type () -> GType
  {
    return progressbar_class_.init ().get_type ();
  }

  auto
  ProgressBar::get_base_type () -> GType
  {
    return gtk_progress_bar_get_type ();
  }

  ProgressBar::ProgressBar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (progressbar_class_.init ()))
  {
  }

  auto
  ProgressBar::pulse () -> void
  {
    gtk_progress_bar_pulse (gobj ());
  }

  auto
  ProgressBar::get_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_progress_bar_get_text (const_cast<GtkProgressBar*> (gobj ())));
  }

  auto
  ProgressBar::set_text (const glib::ustring& text) -> void
  {
    gtk_progress_bar_set_text (gobj (), text.c_str ());
  }

  auto
  ProgressBar::get_fraction () const -> double
  {
    return gtk_progress_bar_get_fraction (
        const_cast<GtkProgressBar*> (gobj ()));
  }

  auto
  ProgressBar::set_fraction (double fraction) -> void
  {
    gtk_progress_bar_set_fraction (gobj (), fraction);
  }

  auto
  ProgressBar::get_pulse_step () const -> double
  {
    return gtk_progress_bar_get_pulse_step (
        const_cast<GtkProgressBar*> (gobj ()));
  }

  auto
  ProgressBar::set_pulse_step (double fraction) -> void
  {
    gtk_progress_bar_set_pulse_step (gobj (), fraction);
  }

  auto
  ProgressBar::set_inverted (bool inverted) -> void
  {
    gtk_progress_bar_set_inverted (gobj (), static_cast<int> (inverted));
  }

  auto
  ProgressBar::get_inverted () const -> bool
  {
    return gtk_progress_bar_get_inverted (
        const_cast<GtkProgressBar*> (gobj ()));
  }

  auto
  ProgressBar::set_ellipsize (pango::EllipsizeMode mode) -> void
  {
    gtk_progress_bar_set_ellipsize (gobj (),
                                    static_cast<PangoEllipsizeMode> (mode));
  }

  auto
  ProgressBar::get_ellipsize () const -> pango::EllipsizeMode
  {
    return static_cast<pango::EllipsizeMode> (
        gtk_progress_bar_get_ellipsize (const_cast<GtkProgressBar*> (gobj ())));
  }

  auto
  ProgressBar::set_show_text (bool show_text) -> void
  {
    gtk_progress_bar_set_show_text (gobj (), static_cast<int> (show_text));
  }

  auto
  ProgressBar::get_show_text () const -> bool
  {
    return gtk_progress_bar_get_show_text (
        const_cast<GtkProgressBar*> (gobj ()));
  }

  auto
  ProgressBar::property_fraction () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "fraction");
  }

  auto
  ProgressBar::property_fraction () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "fraction");
  }

  auto
  ProgressBar::property_pulse_step () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "pulse-step");
  }

  auto
  ProgressBar::property_pulse_step () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "pulse-step");
  }

  auto
  ProgressBar::property_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "text");
  }

  auto
  ProgressBar::property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "text");
  }

  auto
  ProgressBar::property_ellipsize () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "ellipsize");
  }

  auto
  ProgressBar::property_ellipsize () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "ellipsize");
  }

  auto
  ProgressBar::property_show_text () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-text");
  }

  auto
  ProgressBar::property_show_text () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-text");
  }

  auto
  ProgressBar::property_inverted () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "inverted");
  }

  auto
  ProgressBar::property_inverted () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "inverted");
  }

} // namespace gtk
