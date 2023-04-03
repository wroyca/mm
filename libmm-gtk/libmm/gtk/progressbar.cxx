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

namespace Glib
{

  auto
  wrap (GtkProgressBar* object, bool take_copy) -> Gtk::ProgressBar*
  {
    return dynamic_cast<Gtk::ProgressBar*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ProgressBar_Class::init () -> const Glib::Class&
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
  ProgressBar_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ProgressBar ((GtkProgressBar*) (o)));
  }

  ProgressBar::ProgressBar (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ProgressBar::ProgressBar (GtkProgressBar* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ProgressBar::ProgressBar (ProgressBar&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  ProgressBar::operator= (ProgressBar&& src) noexcept -> ProgressBar&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (progressbar_class_.init ()))
  {
  }

  auto
  ProgressBar::pulse () -> void
  {
    gtk_progress_bar_pulse (gobj ());
  }

  auto
  ProgressBar::get_text () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_progress_bar_get_text (const_cast<GtkProgressBar*> (gobj ())));
  }

  auto
  ProgressBar::set_text (const Glib::ustring& text) -> void
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
  ProgressBar::set_ellipsize (Pango::EllipsizeMode mode) -> void
  {
    gtk_progress_bar_set_ellipsize (gobj (),
                                    static_cast<PangoEllipsizeMode> (mode));
  }

  auto
  ProgressBar::get_ellipsize () const -> Pango::EllipsizeMode
  {
    return static_cast<Pango::EllipsizeMode> (
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
  ProgressBar::property_fraction () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "fraction");
  }

  auto
  ProgressBar::property_fraction () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "fraction");
  }

  auto
  ProgressBar::property_pulse_step () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "pulse-step");
  }

  auto
  ProgressBar::property_pulse_step () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "pulse-step");
  }

  auto
  ProgressBar::property_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "text");
  }

  auto
  ProgressBar::property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "text");
  }

  auto
  ProgressBar::property_ellipsize () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "ellipsize");
  }

  auto
  ProgressBar::property_ellipsize () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "ellipsize");
  }

  auto
  ProgressBar::property_show_text () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-text");
  }

  auto
  ProgressBar::property_show_text () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-text");
  }

  auto
  ProgressBar::property_inverted () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "inverted");
  }

  auto
  ProgressBar::property_inverted () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "inverted");
  }

} // namespace Gtk