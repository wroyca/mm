


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/shortcutaction.hxx>
#include <libmm-gtk/shortcutaction_p.hxx>


/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>
#include <libmm-gtk/widget.hxx>

namespace
{
auto SlotShortcut_callback(GtkWidget* widget, GVariant* args, const gpointer user_data) -> gboolean
{
  const auto the_slot = static_cast<Gtk::CallbackAction::SlotShortcut*>(user_data);

  try
  {
    return (*the_slot)(*Glib::wrap(widget, false), Glib::wrap(args, true));
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return false;
}

} // anonymous namespace

namespace Gtk
{

CallbackAction::CallbackAction(const SlotShortcut& slot)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  // Create a copy of the slot object. A pointer to this will be passed
  // through the callback's user_data parameter. It will be deleted
  // when Glib::destroy_notify_delete<SlotShortcut>() is called.
  ShortcutAction(gtk_callback_action_new(&SlotShortcut_callback, new SlotShortcut(slot),
    &Glib::destroy_notify_delete<SlotShortcut>))
{
}

} // namespace Gtk

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::ShortcutAction::Flags>::value_type() -> GType
{
  return gtk_shortcut_action_flags_get_type();
}


namespace Glib
{

auto wrap(GtkShortcutAction* object, const bool take_copy) -> RefPtr<Gtk::ShortcutAction>
{
  return Glib::make_refptr_for_instance<Gtk::ShortcutAction>( dynamic_cast<Gtk::ShortcutAction*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto ShortcutAction_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ShortcutAction_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_shortcut_action_get_type();

  }

  return *this;
}


auto ShortcutAction_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ShortcutAction_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ShortcutAction((GtkShortcutAction*)object);
}


/* The implementation: */

auto ShortcutAction::gobj_copy() -> GtkShortcutAction*
{
  reference();
  return gobj();
}

ShortcutAction::ShortcutAction(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ShortcutAction::ShortcutAction(GtkShortcutAction* castitem)
: Object((GObject*)castitem)
{}


ShortcutAction::ShortcutAction(ShortcutAction&& src) noexcept
: Object(std::move(src))
{}

auto ShortcutAction::operator=(ShortcutAction&& src) noexcept -> ShortcutAction&
{
  Object::operator=(std::move(src));
  return *this;
}


ShortcutAction::~ShortcutAction() noexcept = default;

ShortcutAction::CppClassType ShortcutAction::shortcutaction_class_; // initialize static member

auto ShortcutAction::get_type() -> GType
{
  return shortcutaction_class_.init().get_type();
}


auto ShortcutAction::get_base_type() -> GType
{
  return gtk_shortcut_action_get_type();
}


ShortcutAction::ShortcutAction()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(shortcutaction_class_.init()))
{


}

auto ShortcutAction::parse_string(const Glib::ustring& string) -> Glib::RefPtr<ShortcutAction>
{
  return Glib::wrap(gtk_shortcut_action_parse_string(string.c_str()));
}

auto ShortcutAction::to_string() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_shortcut_action_to_string(const_cast<GtkShortcutAction*>(gobj())));
}

auto ShortcutAction::activate(Widget& widget, Flags flags, const Glib::VariantBase& args) -> bool
{
  return gtk_shortcut_action_activate(gobj(), static_cast<GtkShortcutActionFlags>(flags), widget.gobj(), const_cast<GVariant*>(args.gobj()));
}


} // namespace Gtk


namespace Glib
{

auto wrap(GtkNothingAction* object, const bool take_copy) -> RefPtr<Gtk::NothingAction>
{
  return Glib::make_refptr_for_instance<Gtk::NothingAction>( dynamic_cast<Gtk::NothingAction*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto NothingAction_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &NothingAction_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_nothing_action_get_type();

  }

  return *this;
}


auto NothingAction_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto NothingAction_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new NothingAction((GtkNothingAction*)object);
}


/* The implementation: */

auto NothingAction::gobj_copy() -> GtkNothingAction*
{
  reference();
  return gobj();
}

NothingAction::NothingAction(const Glib::ConstructParams& construct_params)
:
  ShortcutAction(construct_params)
{

}

NothingAction::NothingAction(GtkNothingAction* castitem)
:
  ShortcutAction((GtkShortcutAction*)castitem)
{}


NothingAction::NothingAction(NothingAction&& src) noexcept
: ShortcutAction(std::move(src))
{}

auto NothingAction::operator=(NothingAction&& src) noexcept -> NothingAction&
{
  ShortcutAction::operator=(std::move(src));
  return *this;
}


NothingAction::~NothingAction() noexcept = default;

NothingAction::CppClassType NothingAction::nothingaction_class_; // initialize static member

auto NothingAction::get_type() -> GType
{
  return nothingaction_class_.init().get_type();
}


auto NothingAction::get_base_type() -> GType
{
  return gtk_nothing_action_get_type();
}

NothingAction::NothingAction()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  ShortcutAction(Glib::ConstructParams(nothingaction_class_.init()))
{


}

auto NothingAction::get() -> Glib::RefPtr<NothingAction>
{

  auto retvalue = Glib::wrap(GTK_NOTHING_ACTION(gtk_nothing_action_get()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}


} // namespace Gtk


namespace Glib
{

auto wrap(GtkCallbackAction* object, const bool take_copy) -> RefPtr<Gtk::CallbackAction>
{
  return Glib::make_refptr_for_instance<Gtk::CallbackAction>( dynamic_cast<Gtk::CallbackAction*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto CallbackAction_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CallbackAction_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_callback_action_get_type();

  }

  return *this;
}


auto CallbackAction_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CallbackAction_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new CallbackAction((GtkCallbackAction*)object);
}


/* The implementation: */

auto CallbackAction::gobj_copy() -> GtkCallbackAction*
{
  reference();
  return gobj();
}

CallbackAction::CallbackAction(const Glib::ConstructParams& construct_params)
:
  ShortcutAction(construct_params)
{

}

CallbackAction::CallbackAction(GtkCallbackAction* castitem)
:
  ShortcutAction((GtkShortcutAction*)castitem)
{}


CallbackAction::CallbackAction(CallbackAction&& src) noexcept
: ShortcutAction(std::move(src))
{}

auto CallbackAction::operator=(CallbackAction&& src) noexcept -> CallbackAction&
{
  ShortcutAction::operator=(std::move(src));
  return *this;
}


CallbackAction::~CallbackAction() noexcept = default;

CallbackAction::CppClassType CallbackAction::callbackaction_class_; // initialize static member

auto CallbackAction::get_type() -> GType
{
  return callbackaction_class_.init().get_type();
}


auto CallbackAction::get_base_type() -> GType
{
  return gtk_callback_action_get_type();
}

auto CallbackAction::create(const SlotShortcut& slot) -> Glib::RefPtr<CallbackAction>
{
  return Glib::make_refptr_for_instance<CallbackAction>( new CallbackAction(slot) );
}


} // namespace Gtk


namespace Glib
{

auto wrap(GtkMnemonicAction* object, const bool take_copy) -> RefPtr<Gtk::MnemonicAction>
{
  return Glib::make_refptr_for_instance<Gtk::MnemonicAction>( dynamic_cast<Gtk::MnemonicAction*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto MnemonicAction_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MnemonicAction_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_mnemonic_action_get_type();

  }

  return *this;
}


auto MnemonicAction_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MnemonicAction_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MnemonicAction((GtkMnemonicAction*)object);
}


/* The implementation: */

auto MnemonicAction::gobj_copy() -> GtkMnemonicAction*
{
  reference();
  return gobj();
}

MnemonicAction::MnemonicAction(const Glib::ConstructParams& construct_params)
:
  ShortcutAction(construct_params)
{

}

MnemonicAction::MnemonicAction(GtkMnemonicAction* castitem)
:
  ShortcutAction((GtkShortcutAction*)castitem)
{}


MnemonicAction::MnemonicAction(MnemonicAction&& src) noexcept
: ShortcutAction(std::move(src))
{}

auto MnemonicAction::operator=(MnemonicAction&& src) noexcept -> MnemonicAction&
{
  ShortcutAction::operator=(std::move(src));
  return *this;
}


MnemonicAction::~MnemonicAction() noexcept = default;

MnemonicAction::CppClassType MnemonicAction::mnemonicaction_class_; // initialize static member

auto MnemonicAction::get_type() -> GType
{
  return mnemonicaction_class_.init().get_type();
}


auto MnemonicAction::get_base_type() -> GType
{
  return gtk_mnemonic_action_get_type();
}

MnemonicAction::MnemonicAction()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  ShortcutAction(Glib::ConstructParams(mnemonicaction_class_.init()))
{


}

auto MnemonicAction::get() -> Glib::RefPtr<MnemonicAction>
{

  auto retvalue = Glib::wrap(GTK_MNEMONIC_ACTION(gtk_mnemonic_action_get()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}


} // namespace Gtk


namespace Glib
{

auto wrap(GtkActivateAction* object, const bool take_copy) -> RefPtr<Gtk::ActivateAction>
{
  return Glib::make_refptr_for_instance<Gtk::ActivateAction>( dynamic_cast<Gtk::ActivateAction*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto ActivateAction_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ActivateAction_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_activate_action_get_type();

  }

  return *this;
}


auto ActivateAction_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ActivateAction_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ActivateAction((GtkActivateAction*)object);
}


/* The implementation: */

auto ActivateAction::gobj_copy() -> GtkActivateAction*
{
  reference();
  return gobj();
}

ActivateAction::ActivateAction(const Glib::ConstructParams& construct_params)
:
  ShortcutAction(construct_params)
{

}

ActivateAction::ActivateAction(GtkActivateAction* castitem)
:
  ShortcutAction((GtkShortcutAction*)castitem)
{}


ActivateAction::ActivateAction(ActivateAction&& src) noexcept
: ShortcutAction(std::move(src))
{}

auto ActivateAction::operator=(ActivateAction&& src) noexcept -> ActivateAction&
{
  ShortcutAction::operator=(std::move(src));
  return *this;
}


ActivateAction::~ActivateAction() noexcept = default;

ActivateAction::CppClassType ActivateAction::activateaction_class_; // initialize static member

auto ActivateAction::get_type() -> GType
{
  return activateaction_class_.init().get_type();
}


auto ActivateAction::get_base_type() -> GType
{
  return gtk_activate_action_get_type();
}

ActivateAction::ActivateAction()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  ShortcutAction(Glib::ConstructParams(activateaction_class_.init()))
{


}

auto ActivateAction::get() -> Glib::RefPtr<ActivateAction>
{

  auto retvalue = Glib::wrap(GTK_ACTIVATE_ACTION(gtk_activate_action_get()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}


} // namespace Gtk


namespace Glib
{

auto wrap(GtkSignalAction* object, const bool take_copy) -> RefPtr<Gtk::SignalAction>
{
  return Glib::make_refptr_for_instance<Gtk::SignalAction>( dynamic_cast<Gtk::SignalAction*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto SignalAction_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SignalAction_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_signal_action_get_type();

  }

  return *this;
}


auto SignalAction_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SignalAction_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SignalAction((GtkSignalAction*)object);
}


/* The implementation: */

auto SignalAction::gobj_copy() -> GtkSignalAction*
{
  reference();
  return gobj();
}

SignalAction::SignalAction(const Glib::ConstructParams& construct_params)
:
  ShortcutAction(construct_params)
{

}

SignalAction::SignalAction(GtkSignalAction* castitem)
:
  ShortcutAction((GtkShortcutAction*)castitem)
{}


SignalAction::SignalAction(SignalAction&& src) noexcept
: ShortcutAction(std::move(src))
{}

auto SignalAction::operator=(SignalAction&& src) noexcept -> SignalAction&
{
  ShortcutAction::operator=(std::move(src));
  return *this;
}


SignalAction::~SignalAction() noexcept = default;

SignalAction::CppClassType SignalAction::signalaction_class_; // initialize static member

auto SignalAction::get_type() -> GType
{
  return signalaction_class_.init().get_type();
}


auto SignalAction::get_base_type() -> GType
{
  return gtk_signal_action_get_type();
}

SignalAction::SignalAction(const Glib::ustring& signal_name)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  ShortcutAction(Glib::ConstructParams(signalaction_class_.init(), "signal_name", signal_name.c_str(), nullptr))
{


}

auto SignalAction::create(const Glib::ustring& signal_name) -> Glib::RefPtr<SignalAction>
{
  return Glib::make_refptr_for_instance<SignalAction>( new SignalAction(signal_name) );
}

auto SignalAction::get_signal_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_signal_action_get_signal_name(const_cast<GtkSignalAction*>(gobj())));
}


auto SignalAction::property_signal_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "signal-name"};
}


} // namespace Gtk


namespace Glib
{

auto wrap(GtkNamedAction* object, const bool take_copy) -> RefPtr<Gtk::NamedAction>
{
  return Glib::make_refptr_for_instance<Gtk::NamedAction>( dynamic_cast<Gtk::NamedAction*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto NamedAction_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &NamedAction_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_named_action_get_type();

  }

  return *this;
}


auto NamedAction_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto NamedAction_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new NamedAction((GtkNamedAction*)object);
}


/* The implementation: */

auto NamedAction::gobj_copy() -> GtkNamedAction*
{
  reference();
  return gobj();
}

NamedAction::NamedAction(const Glib::ConstructParams& construct_params)
:
  ShortcutAction(construct_params)
{

}

NamedAction::NamedAction(GtkNamedAction* castitem)
:
  ShortcutAction((GtkShortcutAction*)castitem)
{}


NamedAction::NamedAction(NamedAction&& src) noexcept
: ShortcutAction(std::move(src))
{}

auto NamedAction::operator=(NamedAction&& src) noexcept -> NamedAction&
{
  ShortcutAction::operator=(std::move(src));
  return *this;
}


NamedAction::~NamedAction() noexcept = default;

NamedAction::CppClassType NamedAction::namedaction_class_; // initialize static member

auto NamedAction::get_type() -> GType
{
  return namedaction_class_.init().get_type();
}


auto NamedAction::get_base_type() -> GType
{
  return gtk_named_action_get_type();
}

NamedAction::NamedAction(const Glib::ustring& action_name)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  ShortcutAction(Glib::ConstructParams(namedaction_class_.init(), "action_name", action_name.c_str(), nullptr))
{


}

auto NamedAction::create(const Glib::ustring& action_name) -> Glib::RefPtr<NamedAction>
{
  return Glib::make_refptr_for_instance<NamedAction>( new NamedAction(action_name) );
}

auto NamedAction::get_action_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_named_action_get_action_name(const_cast<GtkNamedAction*>(gobj())));
}


auto NamedAction::property_action_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "action-name"};
}


} // namespace Gtk


