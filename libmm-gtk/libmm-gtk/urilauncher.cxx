// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/urilauncher.hxx>
#include <libmm-gtk/urilauncher_p.hxx>

#include <libmm-gio/slot_async.hxx>
#include <libmm-gtk/window.hxx>

namespace Gtk
{

  UriLauncher::UriLauncher (const Glib::ustring& uri)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (urilauncher_class_.init (),
                                           "uri",
                                           Glib::c_str_or_nullptr (uri),
                                           nullptr))
  {
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkUriLauncher* object, bool take_copy) -> Glib::RefPtr<Gtk::UriLauncher>
  {
    return Glib::make_refptr_for_instance<Gtk::UriLauncher> (
        dynamic_cast<Gtk::UriLauncher*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  UriLauncher_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_uri_launcher_get_type ();
    }

    return *this;
  }

  auto
  UriLauncher_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new UriLauncher ((GtkUriLauncher*) object);
  }

  auto
  UriLauncher::gobj_copy () -> GtkUriLauncher*
  {
    reference ();
    return gobj ();
  }

  UriLauncher::UriLauncher (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  UriLauncher::UriLauncher (GtkUriLauncher* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  UriLauncher::UriLauncher (UriLauncher&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  UriLauncher::operator= (UriLauncher&& src) noexcept -> UriLauncher&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  UriLauncher::~UriLauncher () noexcept {}

  UriLauncher::CppClassType UriLauncher::urilauncher_class_;

  auto
  UriLauncher::get_type () -> GType
  {
    return urilauncher_class_.init ().get_type ();
  }

  auto
  UriLauncher::get_base_type () -> GType
  {
    return gtk_uri_launcher_get_type ();
  }

  auto
  UriLauncher::create (const Glib::ustring& uri) -> Glib::RefPtr<UriLauncher>
  {
    return Glib::make_refptr_for_instance<UriLauncher> (new UriLauncher (uri));
  }

  auto
  UriLauncher::get_uri () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_uri_launcher_get_uri (const_cast<GtkUriLauncher*> (gobj ())));
  }

  auto
  UriLauncher::set_uri (const Glib::ustring& uri) -> void
  {
    gtk_uri_launcher_set_uri (gobj (), uri.empty () ? nullptr : uri.c_str ());
  }

  auto
  UriLauncher::launch (Window& parent,
                       const Gio::SlotAsyncReady& slot,
                       const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_uri_launcher_launch (
        const_cast<GtkUriLauncher*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  UriLauncher::launch (const Gio::SlotAsyncReady& slot,
                       const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_uri_launcher_launch (
        const_cast<GtkUriLauncher*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  UriLauncher::launch_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_uri_launcher_launch_finish (
        const_cast<GtkUriLauncher*> (gobj ()),
        Glib::unwrap (result),
        &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  UriLauncher::property_uri () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "uri");
  }

  auto
  UriLauncher::property_uri () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "uri");
  }

} // namespace Gtk
