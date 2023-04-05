// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/mountoperation.hxx>
#include <libmm/gio/mountoperation_p.hxx>

#include <gio/gio.h>
#include <libmm/glib/exceptionhandler.hxx>

namespace
{

  auto
  MountOperation_signal_ask_password_callback (GMountOperation* self,
                                               const gchar* p0,
                                               const gchar* p1,
                                               const gchar* p2,
                                               GAskPasswordFlags p3,
                                               void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::ustring&,
                                      const glib::ustring&,
                                      const glib::ustring&,
                                      AskPasswordFlags)>;

    const auto obj = dynamic_cast<MountOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0),
              glib::convert_const_gchar_ptr_to_ustring (p1),
              glib::convert_const_gchar_ptr_to_ustring (p2),
              static_cast<AskPasswordFlags> (p3));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo MountOperation_signal_ask_password_info = {
      "ask_password",
      (GCallback) &MountOperation_signal_ask_password_callback,
      (GCallback) &MountOperation_signal_ask_password_callback};

  auto
  MountOperation_signal_ask_question_callback (GMountOperation* self,
                                               const gchar* p0,
                                               const gchar** p1,
                                               void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::ustring&,
                                      const std::vector<glib::ustring>&)>;

    const auto obj = dynamic_cast<MountOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0),
              glib::ArrayHandler<glib::ustring>::array_to_vector (
                  p1,
                  glib::OWNERSHIP_NONE));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo MountOperation_signal_ask_question_info = {
      "ask_question",
      (GCallback) &MountOperation_signal_ask_question_callback,
      (GCallback) &MountOperation_signal_ask_question_callback};

  auto
  MountOperation_signal_reply_callback (GMountOperation* self,
                                        GMountOperationResult p0,
                                        void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (MountOperationResult)>;

    const auto obj = dynamic_cast<MountOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              static_cast<MountOperationResult> (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo MountOperation_signal_reply_info = {
      "reply",
      (GCallback) &MountOperation_signal_reply_callback,
      (GCallback) &MountOperation_signal_reply_callback};

  const glib::SignalProxyInfo MountOperation_signal_aborted_info = {
      "aborted",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  auto
  MountOperation_signal_show_unmount_progress_callback (GMountOperation* self,
                                                        const gchar* p0,
                                                        const gint64 p1,
                                                        const gint64 p2,
                                                        void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::ustring&, gint64, gint64)>;

    const auto obj = dynamic_cast<MountOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (glib::convert_const_gchar_ptr_to_ustring (p0), p1, p2);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo MountOperation_signal_show_unmount_progress_info =
      {"show_unmount_progress",
       (GCallback) &MountOperation_signal_show_unmount_progress_callback,
       (GCallback) &MountOperation_signal_show_unmount_progress_callback};

} // namespace

auto
glib::Value<gio::PasswordSave>::value_type () -> GType
{
  return g_password_save_get_type ();
}

namespace glib
{

  auto
  wrap (GMountOperation* object, const bool take_copy) -> RefPtr<gio::MountOperation>
  {
    return glib::make_refptr_for_instance<gio::MountOperation> (
        dynamic_cast<gio::MountOperation*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  MountOperation_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MountOperation_Class::class_init_function;

      register_derived_type (g_mount_operation_get_type ());
    }

    return *this;
  }

  auto
  MountOperation_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->ask_password = &ask_password_callback;
    klass->ask_question = &ask_question_callback;
    klass->reply = &reply_callback;
    klass->aborted = &aborted_callback;
    klass->show_unmount_progress = &show_unmount_progress_callback;
  }

  auto
  MountOperation_Class::ask_password_callback (GMountOperation* self,
                                               const gchar* p0,
                                               const gchar* p1,
                                               const gchar* p2,
                                               GAskPasswordFlags p3) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_ask_password (glib::convert_const_gchar_ptr_to_ustring (p0),
                                glib::convert_const_gchar_ptr_to_ustring (p1),
                                glib::convert_const_gchar_ptr_to_ustring (p2),
                                static_cast<AskPasswordFlags> (p3));
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

    if (base && base->ask_password)
      (*base->ask_password) (self, p0, p1, p2, p3);
  }

  auto
  MountOperation_Class::ask_question_callback (GMountOperation* self,
                                               const gchar* p0,
                                               const gchar** p1) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_ask_question (
              glib::convert_const_gchar_ptr_to_ustring (p0),
              glib::ArrayHandler<glib::ustring>::array_to_vector (
                  p1,
                  glib::OWNERSHIP_NONE));
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

    if (base && base->ask_question)
      (*base->ask_question) (self, p0, p1);
  }

  auto
  MountOperation_Class::reply_callback (GMountOperation* self,
                                        GMountOperationResult p0) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_reply (static_cast<MountOperationResult> (p0));
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

    if (base && base->reply)
      (*base->reply) (self, p0);
  }

  auto
  MountOperation_Class::aborted_callback (GMountOperation* self) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_aborted ();
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

    if (base && base->aborted)
      (*base->aborted) (self);
  }

  auto
  MountOperation_Class::show_unmount_progress_callback (GMountOperation* self,
                                                        const gchar* p0,
                                                        const gint64 p1,
                                                        const gint64 p2) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_show_unmount_progress (
              glib::convert_const_gchar_ptr_to_ustring (p0),
              p1,
              p2);
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

    if (base && base->show_unmount_progress)
      (*base->show_unmount_progress) (self, p0, p1, p2);
  }

  auto
  MountOperation_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MountOperation ((GMountOperation*) object);
  }

  auto
  MountOperation::gobj_copy () -> GMountOperation*
  {
    reference ();
    return gobj ();
  }

  MountOperation::MountOperation (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  MountOperation::MountOperation (GMountOperation* castitem)
    : Object ((GObject*) castitem)
  {
  }

  MountOperation::MountOperation (MountOperation&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  MountOperation::operator= (MountOperation&& src) noexcept -> MountOperation&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  MountOperation::~MountOperation () noexcept = default;

  MountOperation::CppClassType MountOperation::mountoperation_class_;

  auto
  MountOperation::get_type () -> GType
  {
    return mountoperation_class_.init ().get_type ();
  }

  auto
  MountOperation::get_base_type () -> GType
  {
    return g_mount_operation_get_type ();
  }

  MountOperation::MountOperation ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (mountoperation_class_.init ()))
  {
  }

  auto
  MountOperation::create () -> glib::RefPtr<MountOperation>
  {
    return glib::make_refptr_for_instance<MountOperation> (
        new MountOperation ());
  }

  auto
  MountOperation::get_username () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_mount_operation_get_username (
            const_cast<GMountOperation*> (gobj ())));
  }

  auto
  MountOperation::set_username (const glib::ustring& username) -> void
  {
    g_mount_operation_set_username (gobj (), username.c_str ());
  }

  auto
  MountOperation::get_password () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_mount_operation_get_password (
            const_cast<GMountOperation*> (gobj ())));
  }

  auto
  MountOperation::set_password (const glib::ustring& password) -> void
  {
    g_mount_operation_set_password (gobj (), password.c_str ());
  }

  auto
  MountOperation::get_anonymous () const -> bool
  {
    return g_mount_operation_get_anonymous (
        const_cast<GMountOperation*> (gobj ()));
  }

  auto
  MountOperation::set_anonymous (const bool anonymous) -> void
  {
    g_mount_operation_set_anonymous (gobj (), anonymous);
  }

  auto
  MountOperation::get_domain () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_mount_operation_get_domain (const_cast<GMountOperation*> (gobj ())));
  }

  auto
  MountOperation::set_domain (const glib::ustring& domain) -> void
  {
    g_mount_operation_set_domain (gobj (), domain.c_str ());
  }

  auto
  MountOperation::get_password_save () const -> PasswordSave
  {
    return (PasswordSave) g_mount_operation_get_password_save (
        const_cast<GMountOperation*> (gobj ()));
  }

  auto
  MountOperation::set_password_save (PasswordSave save) -> void
  {
    g_mount_operation_set_password_save (gobj (), (GPasswordSave) save);
  }

  auto
  MountOperation::get_choice () const -> int
  {
    return g_mount_operation_get_choice (
        const_cast<GMountOperation*> (gobj ()));
  }

  auto
  MountOperation::set_choice (const int choice) -> void
  {
    g_mount_operation_set_choice (gobj (), choice);
  }

  auto
  MountOperation::reply (MountOperationResult result) -> void
  {
    g_mount_operation_reply (gobj (),
                             static_cast<GMountOperationResult> (result));
  }

  auto
  MountOperation::signal_ask_password () -> glib::SignalProxy<void (const glib::ustring&,
                                 const glib::ustring&,
                                 const glib::ustring&,
                                 AskPasswordFlags)>
  {
    return {this, &MountOperation_signal_ask_password_info};
  }

  auto
  MountOperation::signal_ask_question () -> glib::SignalProxy<void (const glib::ustring&,
                                 const std::vector<glib::ustring>&)>
  {
    return {this, &MountOperation_signal_ask_question_info};
  }

  auto
  MountOperation::signal_reply () -> glib::SignalProxy<void (MountOperationResult)>
  {
    return {this, &MountOperation_signal_reply_info};
  }

  auto
  MountOperation::signal_aborted () -> glib::SignalProxy<void ()>
  {
    return {this, &MountOperation_signal_aborted_info};
  }

  auto
  MountOperation::signal_show_unmount_progress () -> glib::SignalProxy<void (const glib::ustring&, gint64, gint64)>
  {
    return {this, &MountOperation_signal_show_unmount_progress_info};
  }

  auto
  MountOperation::property_username () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "username"};
  }

  auto
  MountOperation::property_username () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "username"};
  }

  auto
  MountOperation::property_password () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "password"};
  }

  auto
  MountOperation::property_password () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "password"};
  }

  auto
  MountOperation::property_anonymous () -> glib::PropertyProxy<bool>
  {
    return {this, "anonymous"};
  }

  auto
  MountOperation::property_anonymous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "anonymous"};
  }

  auto
  MountOperation::property_domain () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "domain"};
  }

  auto
  MountOperation::property_domain () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "domain"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<PasswordSave>::value,
      "Type PasswordSave cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MountOperation::property_password_save () -> glib::PropertyProxy<PasswordSave>
  {
    return {this, "password-save"};
  }

  auto
  MountOperation::property_password_save () const -> glib::PropertyProxy_ReadOnly<PasswordSave>
  {
    return {this, "password-save"};
  }

  auto
  MountOperation::property_choice () -> glib::PropertyProxy<int>
  {
    return {this, "choice"};
  }

  auto
  MountOperation::property_choice () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "choice"};
  }

  auto
  MountOperation::on_ask_password (const glib::ustring& message,
                                   const glib::ustring& default_user,
                                   const glib::ustring& default_domain,
                                   AskPasswordFlags flags) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->ask_password)
      (*base->ask_password) (gobj (),
                             message.c_str (),
                             default_user.c_str (),
                             default_domain.c_str (),
                             static_cast<GAskPasswordFlags> (flags));
  }

  auto
  MountOperation::on_ask_question (const glib::ustring& message,
                                   const std::vector<glib::ustring>& choices) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->ask_question)
      (*base->ask_question) (
          gobj (),
          message.c_str (),
          glib::ArrayHandler<glib::ustring>::vector_to_array (choices).data ());
  }

  auto
  MountOperation::on_reply (MountOperationResult result) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->reply)
      (*base->reply) (gobj (), static_cast<GMountOperationResult> (result));
  }

  auto
  MountOperation::on_aborted () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->aborted)
      (*base->aborted) (gobj ());
  }

  auto
  MountOperation::on_show_unmount_progress (const glib::ustring& message,
                                            const gint64 time_left,
                                            const gint64 bytes_left) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->show_unmount_progress)
      (*base->show_unmount_progress) (gobj (),
                                      message.c_str (),
                                      time_left,
                                      bytes_left);
  }

} // namespace gio
