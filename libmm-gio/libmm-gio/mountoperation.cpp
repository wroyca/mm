


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/mountoperation.hpp>
#include <mm/gio/private/mountoperation_p.hpp>


/* Copyright (C) 2007 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <mm/glib/exceptionhandler.hpp>

namespace
{


auto MountOperation_signal_ask_password_callback (
  GMountOperation *self, const gchar *p0, const gchar *p1, const gchar *p2, GAskPasswordFlags p3,
  void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::ustring&, const Glib::ustring&, const Glib::ustring&, AskPasswordFlags)>;

  const auto obj = dynamic_cast<MountOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
, Glib::convert_const_gchar_ptr_to_ustring(p1)
, Glib::convert_const_gchar_ptr_to_ustring(p2)
, static_cast<AskPasswordFlags>(p3)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo MountOperation_signal_ask_password_info =
{
  "ask_password",
  (GCallback) &MountOperation_signal_ask_password_callback,
  (GCallback) &MountOperation_signal_ask_password_callback
};


auto MountOperation_signal_ask_question_callback (
  GMountOperation *self, const gchar *p0, const gchar **p1, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::ustring&, const std::vector<Glib::ustring>&)>;

  const auto obj = dynamic_cast<MountOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
, Glib::ArrayHandler<Glib::ustring>::array_to_vector(p1, Glib::OWNERSHIP_NONE)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo MountOperation_signal_ask_question_info =
{
  "ask_question",
  (GCallback) &MountOperation_signal_ask_question_callback,
  (GCallback) &MountOperation_signal_ask_question_callback
};


auto MountOperation_signal_reply_callback (
  GMountOperation *self, GMountOperationResult p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(MountOperationResult)>;

  const auto obj = dynamic_cast<MountOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(static_cast<MountOperationResult>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo MountOperation_signal_reply_info =
{
  "reply",
  (GCallback) &MountOperation_signal_reply_callback,
  (GCallback) &MountOperation_signal_reply_callback
};


const Glib::SignalProxyInfo MountOperation_signal_aborted_info =
{
  "aborted",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto MountOperation_signal_show_unmount_progress_callback (
  GMountOperation *self, const gchar *p0, const gint64 p1, const gint64 p2, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::ustring&, gint64, gint64)>;

  const auto obj = dynamic_cast<MountOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
, p1, p2);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo MountOperation_signal_show_unmount_progress_info =
{
  "show_unmount_progress",
  (GCallback) &MountOperation_signal_show_unmount_progress_callback,
  (GCallback) &MountOperation_signal_show_unmount_progress_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gio::PasswordSave>::value_type() -> GType
{
  return g_password_save_get_type();
}


namespace Glib
{

auto wrap(GMountOperation* object, const bool take_copy) -> RefPtr<Gio::MountOperation>
{
  return Glib::make_refptr_for_instance<Gio::MountOperation>( dynamic_cast<Gio::MountOperation*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto MountOperation_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MountOperation_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_mount_operation_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto MountOperation_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->ask_password = &ask_password_callback;
  klass->ask_question = &ask_question_callback;
  klass->reply = &reply_callback;
  klass->aborted = &aborted_callback;
  klass->show_unmount_progress = &show_unmount_progress_callback;
}


auto MountOperation_Class::ask_password_callback (
  GMountOperation *self, const gchar *p0, const gchar *p1, const gchar *p2,
  GAskPasswordFlags p3) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_ask_password(Glib::convert_const_gchar_ptr_to_ustring(p0)
, Glib::convert_const_gchar_ptr_to_ustring(p1)
, Glib::convert_const_gchar_ptr_to_ustring(p2)
, static_cast<AskPasswordFlags>(p3)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->ask_password)
    (*base->ask_password)(self, p0, p1, p2, p3);
}
auto MountOperation_Class::ask_question_callback (
  GMountOperation *self, const gchar *p0, const gchar **p1) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_ask_question(Glib::convert_const_gchar_ptr_to_ustring(p0)
, Glib::ArrayHandler<Glib::ustring>::array_to_vector(p1, Glib::OWNERSHIP_NONE)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->ask_question)
    (*base->ask_question)(self, p0, p1);
}
auto MountOperation_Class::reply_callback (GMountOperation *self, GMountOperationResult p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_reply(static_cast<MountOperationResult>(p0)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->reply)
    (*base->reply)(self, p0);
}
auto MountOperation_Class::aborted_callback (GMountOperation *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_aborted();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->aborted)
    (*base->aborted)(self);
}
auto MountOperation_Class::show_unmount_progress_callback (
  GMountOperation *self, const gchar *p0, const gint64 p1, const gint64 p2) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_show_unmount_progress(Glib::convert_const_gchar_ptr_to_ustring(p0)
, p1, p2);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->show_unmount_progress)
    (*base->show_unmount_progress)(self, p0, p1, p2);
}


auto MountOperation_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MountOperation((GMountOperation*)object);
}


/* The implementation: */

auto MountOperation::gobj_copy() -> GMountOperation*
{
  reference();
  return gobj();
}

MountOperation::MountOperation(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

MountOperation::MountOperation(GMountOperation* castitem)
: Object((GObject*)castitem)
{}


MountOperation::MountOperation(MountOperation&& src) noexcept
: Object(std::move(src))
{}

auto MountOperation::operator=(MountOperation&& src) noexcept -> MountOperation&
{
  Object::operator=(std::move(src));
  return *this;
}


MountOperation::~MountOperation() noexcept = default;

MountOperation::CppClassType MountOperation::mountoperation_class_; // initialize static member

auto MountOperation::get_type() -> GType
{
  return mountoperation_class_.init().get_type();
}


auto MountOperation::get_base_type() -> GType
{
  return g_mount_operation_get_type();
}


MountOperation::MountOperation()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(mountoperation_class_.init()))
{


}

auto MountOperation::create() -> Glib::RefPtr<MountOperation>
{
  return Glib::make_refptr_for_instance<MountOperation>( new MountOperation() );
}

auto MountOperation::get_username() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_mount_operation_get_username(const_cast<GMountOperation*>(gobj())));
}

auto MountOperation::set_username (const Glib::ustring &username) -> void
{
  g_mount_operation_set_username(gobj(), username.c_str());
}

auto MountOperation::get_password() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_mount_operation_get_password(const_cast<GMountOperation*>(gobj())));
}

auto MountOperation::set_password (const Glib::ustring &password) -> void
{
  g_mount_operation_set_password(gobj(), password.c_str());
}

auto MountOperation::get_anonymous() const -> bool
{
  return g_mount_operation_get_anonymous(const_cast<GMountOperation*>(gobj()));
}

auto MountOperation::set_anonymous (
  const bool anonymous) -> void
{
  g_mount_operation_set_anonymous(gobj(), anonymous);
}

auto MountOperation::get_domain() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_mount_operation_get_domain(const_cast<GMountOperation*>(gobj())));
}

auto MountOperation::set_domain (const Glib::ustring &domain) -> void
{
  g_mount_operation_set_domain(gobj(), domain.c_str());
}

auto MountOperation::get_password_save() const -> PasswordSave
{
  return (PasswordSave)g_mount_operation_get_password_save(const_cast<GMountOperation*>(gobj()));
}

auto MountOperation::set_password_save (PasswordSave save) -> void
{
  g_mount_operation_set_password_save(gobj(), (GPasswordSave)save);
}

auto MountOperation::get_choice() const -> int
{
  return g_mount_operation_get_choice(const_cast<GMountOperation*>(gobj()));
}

auto MountOperation::set_choice (
  const int choice) -> void
{
  g_mount_operation_set_choice(gobj(), choice);
}

auto MountOperation::reply (MountOperationResult result) -> void
{
  g_mount_operation_reply(gobj(), static_cast<GMountOperationResult>(result));
}


auto MountOperation::signal_ask_password() -> Glib::SignalProxy<void(const Glib::ustring&, const Glib::ustring&, const Glib::ustring&, AskPasswordFlags)>
{
  return {this, &MountOperation_signal_ask_password_info};
}


auto MountOperation::signal_ask_question() -> Glib::SignalProxy<void(const Glib::ustring&, const std::vector<Glib::ustring>&)>
{
  return {this, &MountOperation_signal_ask_question_info};
}


auto MountOperation::signal_reply() -> Glib::SignalProxy<void(MountOperationResult)>
{
  return {this, &MountOperation_signal_reply_info};
}


auto MountOperation::signal_aborted() -> Glib::SignalProxy<void()>
{
  return {this, &MountOperation_signal_aborted_info};
}


auto MountOperation::signal_show_unmount_progress() -> Glib::SignalProxy<void(const Glib::ustring&, gint64, gint64)>
{
  return {this, &MountOperation_signal_show_unmount_progress_info};
}


auto MountOperation::property_username() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "username"};
}

auto MountOperation::property_username() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "username"};
}

auto MountOperation::property_password() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "password"};
}

auto MountOperation::property_password() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "password"};
}

auto MountOperation::property_anonymous() -> Glib::PropertyProxy< bool >
{
  return {this, "anonymous"};
}

auto MountOperation::property_anonymous() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "anonymous"};
}

auto MountOperation::property_domain() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "domain"};
}

auto MountOperation::property_domain() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "domain"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<PasswordSave>::value,
  "Type PasswordSave cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto MountOperation::property_password_save() -> Glib::PropertyProxy< PasswordSave >
{
  return {this, "password-save"};
}

auto MountOperation::property_password_save() const -> Glib::PropertyProxy_ReadOnly< PasswordSave >
{
  return {this, "password-save"};
}

auto MountOperation::property_choice() -> Glib::PropertyProxy< int >
{
  return {this, "choice"};
}

auto MountOperation::property_choice() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "choice"};
}


auto MountOperation::on_ask_password (
  const Glib::ustring &message, const Glib::ustring &default_user,
  const Glib::ustring &default_domain, AskPasswordFlags flags) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->ask_password)
    (*base->ask_password)(gobj(),message.c_str(),default_user.c_str(),default_domain.c_str(),static_cast<GAskPasswordFlags>(flags));
}
auto MountOperation::on_ask_question (
  const Glib::ustring &message, const std::vector <Glib::ustring> &choices) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->ask_question)
    (*base->ask_question)(gobj(),message.c_str(),Glib::ArrayHandler<Glib::ustring>::vector_to_array(choices).data());
}
auto MountOperation::on_reply (MountOperationResult result) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->reply)
    (*base->reply)(gobj(),static_cast<GMountOperationResult>(result));
}
auto MountOperation::on_aborted () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->aborted)
    (*base->aborted)(gobj());
}
auto MountOperation::on_show_unmount_progress (
  const Glib::ustring &message, const gint64 time_left, const gint64 bytes_left) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->show_unmount_progress)
    (*base->show_unmount_progress)(gobj(),message.c_str(),time_left,bytes_left);
}


} // namespace Gio


