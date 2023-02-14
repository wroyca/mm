// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/nativedialog.hxx>
#include <libmm-gtk/nativedialog_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/window.hxx>

namespace Gtk
{

  auto
  NativeDialog::unset_transient_for () -> void
  {
    gtk_native_dialog_set_transient_for (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{

  auto
  NativeDialog_signal_response_callback (GtkNativeDialog* self,
                                         const gint p0,
                                         void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (int)>;

    const auto obj = dynamic_cast<NativeDialog*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo NativeDialog_signal_response_info = {
      "response",
      (GCallback) &NativeDialog_signal_response_callback,
      (GCallback) &NativeDialog_signal_response_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkNativeDialog* object, const bool take_copy) -> RefPtr<Gtk::NativeDialog>
  {
    return Glib::make_refptr_for_instance<Gtk::NativeDialog> (
        dynamic_cast<Gtk::NativeDialog*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  NativeDialog_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &NativeDialog_Class::class_init_function;

      register_derived_type (gtk_native_dialog_get_type ());
    }

    return *this;
  }

  auto
  NativeDialog_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->response = &response_callback;
  }

  auto
  NativeDialog_Class::response_callback (GtkNativeDialog* self, const gint p0) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_response (p0);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->response)
      (*base->response) (self, p0);
  }

  auto
  NativeDialog_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new NativeDialog ((GtkNativeDialog*) object);
  }

  auto
  NativeDialog::gobj_copy () -> GtkNativeDialog*
  {
    reference ();
    return gobj ();
  }

  NativeDialog::NativeDialog (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  NativeDialog::NativeDialog (GtkNativeDialog* castitem)
    : Object ((GObject*) castitem)
  {
  }

  NativeDialog::NativeDialog (NativeDialog&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  NativeDialog::operator= (NativeDialog&& src) noexcept -> NativeDialog&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  NativeDialog::~NativeDialog () noexcept = default;

  NativeDialog::CppClassType NativeDialog::nativedialog_class_;

  auto
  NativeDialog::get_type () -> GType
  {
    return nativedialog_class_.init ().get_type ();
  }

  auto
  NativeDialog::get_base_type () -> GType
  {
    return gtk_native_dialog_get_type ();
  }

  NativeDialog::NativeDialog ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (nativedialog_class_.init ()))
  {
  }

  auto
  NativeDialog::show () -> void
  {
    gtk_native_dialog_show (gobj ());
  }

  auto
  NativeDialog::hide () -> void
  {
    gtk_native_dialog_hide (gobj ());
  }

  auto
  NativeDialog::get_visible () const -> bool
  {
    return gtk_native_dialog_get_visible (
        const_cast<GtkNativeDialog*> (gobj ()));
  }

  auto
  NativeDialog::set_modal (const bool modal) -> void
  {
    gtk_native_dialog_set_modal (gobj (), modal);
  }

  auto
  NativeDialog::get_modal () const -> bool
  {
    return gtk_native_dialog_get_modal (const_cast<GtkNativeDialog*> (gobj ()));
  }

  auto
  NativeDialog::set_title (const Glib::ustring& title) -> void
  {
    gtk_native_dialog_set_title (gobj (), title.c_str ());
  }

  auto
  NativeDialog::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_native_dialog_get_title (const_cast<GtkNativeDialog*> (gobj ())));
  }

  auto
  NativeDialog::set_transient_for (Window& parent) -> void
  {
    gtk_native_dialog_set_transient_for (gobj (), parent.gobj ());
  }

  auto
  NativeDialog::get_transient_for () -> Window*
  {
    return Glib::wrap (gtk_native_dialog_get_transient_for (gobj ()));
  }

  auto
  NativeDialog::get_transient_for () const -> const Window*
  {
    return const_cast<NativeDialog*> (this)->get_transient_for ();
  }

  auto
  NativeDialog::signal_response () -> Glib::SignalProxy<void (int)>
  {
    return {this, &NativeDialog_signal_response_info};
  }

  auto
  NativeDialog::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "title"};
  }

  auto
  NativeDialog::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "title"};
  }

  auto
  NativeDialog::property_modal () -> Glib::PropertyProxy<bool>
  {
    return {this, "modal"};
  }

  auto
  NativeDialog::property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "modal"};
  }

  auto
  NativeDialog::property_visible () -> Glib::PropertyProxy<bool>
  {
    return {this, "visible"};
  }

  auto
  NativeDialog::property_visible () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "visible"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Window*>::value,
      "Type Window* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  NativeDialog::property_transient_for () -> Glib::PropertyProxy<Window*>
  {
    return {this, "transient-for"};
  }

  auto
  NativeDialog::property_transient_for () const -> Glib::PropertyProxy_ReadOnly<Window*>
  {
    return {this, "transient-for"};
  }

  auto
  NativeDialog::on_response (const int response_id) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->response)
      (*base->response) (gobj (), response_id);
  }

} // namespace Gtk
