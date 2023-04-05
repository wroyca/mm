// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/nativedialog.hxx>
#include <libmm/gtk/nativedialog_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/window.hxx>

namespace gtk
{

  auto
  NativeDialog::unset_transient_for () -> void
  {
    gtk_native_dialog_set_transient_for (gobj (), nullptr);
  }

} // namespace gtk

namespace
{

  static auto
  NativeDialog_signal_response_callback (GtkNativeDialog* self,
                                         gint p0,
                                         void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (int)>;

    auto obj = dynamic_cast<NativeDialog*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo NativeDialog_signal_response_info = {
      "response",
      (GCallback) &NativeDialog_signal_response_callback,
      (GCallback) &NativeDialog_signal_response_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkNativeDialog* object, bool take_copy) -> glib::RefPtr<gtk::NativeDialog>
  {
    return glib::make_refptr_for_instance<gtk::NativeDialog> (
        dynamic_cast<gtk::NativeDialog*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  NativeDialog_Class::init () -> const glib::Class&
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
  NativeDialog_Class::response_callback (GtkNativeDialog* self, gint p0) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->response)
      (*base->response) (self, p0);
  }

  auto
  NativeDialog_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new NativeDialog ((GtkNativeDialog*) object);
  }

  auto
  NativeDialog::gobj_copy () -> GtkNativeDialog*
  {
    reference ();
    return gobj ();
  }

  NativeDialog::NativeDialog (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  NativeDialog::NativeDialog (GtkNativeDialog* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  NativeDialog::NativeDialog (NativeDialog&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  NativeDialog::operator= (NativeDialog&& src) noexcept -> NativeDialog&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  NativeDialog::~NativeDialog () noexcept {}

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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (nativedialog_class_.init ()))
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
  NativeDialog::set_modal (bool modal) -> void
  {
    gtk_native_dialog_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  NativeDialog::get_modal () const -> bool
  {
    return gtk_native_dialog_get_modal (const_cast<GtkNativeDialog*> (gobj ()));
  }

  auto
  NativeDialog::set_title (const glib::ustring& title) -> void
  {
    gtk_native_dialog_set_title (gobj (), title.c_str ());
  }

  auto
  NativeDialog::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_native_dialog_get_title (const_cast<GtkNativeDialog*> (gobj ())));
  }

  auto
  NativeDialog::set_transient_for (Window& parent) -> void
  {
    gtk_native_dialog_set_transient_for (gobj (), (parent).gobj ());
  }

  auto
  NativeDialog::get_transient_for () -> Window*
  {
    return glib::wrap (gtk_native_dialog_get_transient_for (gobj ()));
  }

  auto
  NativeDialog::get_transient_for () const -> const Window*
  {
    return const_cast<NativeDialog*> (this)->get_transient_for ();
  }

  auto
  NativeDialog::signal_response () -> glib::SignalProxy<void (int)>
  {
    return glib::SignalProxy<void (int)> (this,
                                          &NativeDialog_signal_response_info);
  }

  auto
  NativeDialog::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  NativeDialog::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  NativeDialog::property_modal () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  NativeDialog::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  auto
  NativeDialog::property_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "visible");
  }

  auto
  NativeDialog::property_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "visible");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Window*>::value,
      "Type Window* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  NativeDialog::property_transient_for () -> glib::PropertyProxy<Window*>
  {
    return glib::PropertyProxy<Window*> (this, "transient-for");
  }

  auto
  NativeDialog::property_transient_for () const -> glib::PropertyProxy_ReadOnly<Window*>
  {
    return glib::PropertyProxy_ReadOnly<Window*> (this, "transient-for");
  }

  auto
  gtk::NativeDialog::on_response (int response_id) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->response)
      (*base->response) (gobj (), response_id);
  }

} // namespace gtk
