// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/colordialog.hxx>
#include <libmm/gtk/colordialog_p.hxx>

#include <libmm/gio/slot_async.hxx>
#include <libmm/gtk/window.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkColorDialog* object, bool take_copy) -> glib::RefPtr<gtk::ColorDialog>
  {
    return glib::make_refptr_for_instance<gtk::ColorDialog> (
        dynamic_cast<gtk::ColorDialog*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ColorDialog_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_color_dialog_get_type ();
    }

    return *this;
  }

  auto
  ColorDialog_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ColorDialog ((GtkColorDialog*) object);
  }

  auto
  ColorDialog::gobj_copy () -> GtkColorDialog*
  {
    reference ();
    return gobj ();
  }

  ColorDialog::ColorDialog (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ColorDialog::ColorDialog (GtkColorDialog* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  ColorDialog::ColorDialog (ColorDialog&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  ColorDialog::operator= (ColorDialog&& src) noexcept -> ColorDialog&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (colordialog_class_.init ()))
  {
  }

  auto
  ColorDialog::create () -> glib::RefPtr<ColorDialog>
  {
    return glib::make_refptr_for_instance<ColorDialog> (new ColorDialog ());
  }

  auto
  ColorDialog::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_color_dialog_get_title (const_cast<GtkColorDialog*> (gobj ())));
  }

  auto
  ColorDialog::set_title (const glib::ustring& title) -> void
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
      const gdk::RGBA& initial_color,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_color_dialog_choose_rgba (
        const_cast<GtkColorDialog*> (gobj ()),
        (parent).gobj (),
        (initial_color).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ColorDialog::choose_rgba (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_color_dialog_choose_rgba (
        const_cast<GtkColorDialog*> (gobj ()),
        (parent).gobj (),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ColorDialog::choose_rgba (
      const gdk::RGBA& initial_color,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_color_dialog_choose_rgba (
        const_cast<GtkColorDialog*> (gobj ()),
        nullptr,
        (initial_color).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ColorDialog::choose_rgba (
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_color_dialog_choose_rgba (
        const_cast<GtkColorDialog*> (gobj ()),
        nullptr,
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ColorDialog::choose_rgba_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> gdk::RGBA
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gtk_color_dialog_choose_rgba_finish (
                                    const_cast<GtkColorDialog*> (gobj ()),
                                    glib::unwrap (result),
                                    &(gerror)),
                                false);
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  ColorDialog::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  ColorDialog::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  ColorDialog::property_modal () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  ColorDialog::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  auto
  ColorDialog::property_with_alpha () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "with-alpha");
  }

  auto
  ColorDialog::property_with_alpha () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "with-alpha");
  }

} // namespace gtk
