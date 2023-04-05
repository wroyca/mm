// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/urilauncher.hxx>
#include <libmm/gtk/urilauncher_p.hxx>

#include <libmm/gio/slot_async.hxx>
#include <libmm/gtk/window.hxx>

namespace gtk
{

  UriLauncher::UriLauncher (const glib::ustring& uri)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (urilauncher_class_.init (),
                                           "uri",
                                           glib::c_str_or_nullptr (uri),
                                           nullptr))
  {
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkUriLauncher* object, bool take_copy) -> glib::RefPtr<gtk::UriLauncher>
  {
    return glib::make_refptr_for_instance<gtk::UriLauncher> (
        dynamic_cast<gtk::UriLauncher*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  UriLauncher_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_uri_launcher_get_type ();
    }

    return *this;
  }

  auto
  UriLauncher_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new UriLauncher ((GtkUriLauncher*) object);
  }

  auto
  UriLauncher::gobj_copy () -> GtkUriLauncher*
  {
    reference ();
    return gobj ();
  }

  UriLauncher::UriLauncher (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  UriLauncher::UriLauncher (GtkUriLauncher* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  UriLauncher::UriLauncher (UriLauncher&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  UriLauncher::operator= (UriLauncher&& src) noexcept -> UriLauncher&
  {
    glib::Object::operator= (std::move (src));
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
  UriLauncher::create (const glib::ustring& uri) -> glib::RefPtr<UriLauncher>
  {
    return glib::make_refptr_for_instance<UriLauncher> (new UriLauncher (uri));
  }

  auto
  UriLauncher::get_uri () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_uri_launcher_get_uri (const_cast<GtkUriLauncher*> (gobj ())));
  }

  auto
  UriLauncher::set_uri (const glib::ustring& uri) -> void
  {
    gtk_uri_launcher_set_uri (gobj (), uri.empty () ? nullptr : uri.c_str ());
  }

  auto
  UriLauncher::launch (Window& parent,
                       const gio::SlotAsyncReady& slot,
                       const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_uri_launcher_launch (
        const_cast<GtkUriLauncher*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  UriLauncher::launch (const gio::SlotAsyncReady& slot,
                       const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_uri_launcher_launch (
        const_cast<GtkUriLauncher*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  UriLauncher::launch_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_uri_launcher_launch_finish (
        const_cast<GtkUriLauncher*> (gobj ()),
        glib::unwrap (result),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  UriLauncher::property_uri () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "uri");
  }

  auto
  UriLauncher::property_uri () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "uri");
  }

} // namespace gtk
