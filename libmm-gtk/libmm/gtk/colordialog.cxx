// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/colordialog.hxx>
#include <libmm/gtk/colordialog_p.hxx>

#include <libmm/gio/slot_async.hxx>
#include <libmm/gtk/window.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkColorDialog* object, bool take_copy) -> Glib::RefPtr<Gtk::ColorDialog>
  {
    return Glib::make_refptr_for_instance<Gtk::ColorDialog> (
        dynamic_cast<Gtk::ColorDialog*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ColorDialog_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_color_dialog_get_type ();
    }

    return *this;
  }

  auto
  ColorDialog_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ColorDialog ((GtkColorDialog*) object);
  }

  auto
  ColorDialog::gobj_copy () -> GtkColorDialog*
  {
    reference ();
    return gobj ();
  }

  ColorDialog::ColorDialog (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  ColorDialog::ColorDialog (GtkColorDialog* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  ColorDialog::ColorDialog (ColorDialog&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  ColorDialog::operator= (ColorDialog&& src) noexcept -> ColorDialog&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  ColorDialog::~ColorDialog () noexcept {}

  ColorDialog::CppClassType ColorDialog::colordialog_class_;

  auto
  ColorDialog::get_type () -> GType
  {
    return colordialog_class_.init ().get_type ();
  }

  auto
  ColorDialog::get_base_type () -> GType
  {
    return gtk_color_dialog_get_type ();
  }

  ColorDialog::ColorDialog ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (colordialog_class_.init ()))
  {
  }

  auto
  ColorDialog::create () -> Glib::RefPtr<ColorDialog>
  {
    return Glib::make_refptr_for_instance<ColorDialog> (new ColorDialog ());
  }

  auto
  ColorDialog::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_color_dialog_get_title (const_cast<GtkColorDialog*> (gobj ())));
  }

  auto
  ColorDialog::set_title (const Glib::ustring& title) -> void
  {
    gtk_color_dialog_set_title (gobj (), title.c_str ());
  }

  auto
  ColorDialog::get_modal () const -> bool
  {
    return gtk_color_dialog_get_modal (const_cast<GtkColorDialog*> (gobj ()));
  }

  auto
  ColorDialog::set_modal (bool modal) -> void
  {
    gtk_color_dialog_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  ColorDialog::get_with_alpha () const -> bool
  {
    return gtk_color_dialog_get_with_alpha (
        const_cast<GtkColorDialog*> (gobj ()));
  }

  auto
  ColorDialog::set_with_alpha (bool with_alpha) -> void
  {
    gtk_color_dialog_set_with_alpha (gobj (), static_cast<int> (with_alpha));
  }

  auto
  ColorDialog::choose_rgba (
      Window& parent,
      const Gdk::RGBA& initial_color,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_color_dialog_choose_rgba (
        const_cast<GtkColorDialog*> (gobj ()),
        (parent).gobj (),
        (initial_color).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ColorDialog::choose_rgba (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_color_dialog_choose_rgba (
        const_cast<GtkColorDialog*> (gobj ()),
        (parent).gobj (),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ColorDialog::choose_rgba (
      const Gdk::RGBA& initial_color,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_color_dialog_choose_rgba (
        const_cast<GtkColorDialog*> (gobj ()),
        nullptr,
        (initial_color).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ColorDialog::choose_rgba (
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_color_dialog_choose_rgba (
        const_cast<GtkColorDialog*> (gobj ()),
        nullptr,
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ColorDialog::choose_rgba_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> Gdk::RGBA
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (gtk_color_dialog_choose_rgba_finish (
                                    const_cast<GtkColorDialog*> (gobj ()),
                                    Glib::unwrap (result),
                                    &(gerror)),
                                false);
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  ColorDialog::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  ColorDialog::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  ColorDialog::property_modal () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  ColorDialog::property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  auto
  ColorDialog::property_with_alpha () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "with-alpha");
  }

  auto
  ColorDialog::property_with_alpha () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "with-alpha");
  }

} // namespace Gtk
