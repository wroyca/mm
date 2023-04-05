// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcutaction.hxx>
#include <libmm/gtk/shortcutaction_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/widget.hxx>

namespace
{
  auto
  SlotShortcut_callback (GtkWidget* widget, GVariant* args, gpointer user_data) -> gboolean
  {
    auto the_slot = static_cast<gtk::CallbackAction::SlotShortcut*> (user_data);

    try
    {
      return (*the_slot) (*glib::wrap (widget, false), glib::wrap (args, true));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return false;
  }

} // namespace

namespace gtk
{

  CallbackAction::CallbackAction (const SlotShortcut& slot)
    : glib::ObjectBase (nullptr),

      ShortcutAction (
          gtk_callback_action_new (&SlotShortcut_callback,
                                   new SlotShortcut (slot),
                                   &glib::destroy_notify_delete<SlotShortcut>))
  {
  }

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::ShortcutAction::Flags>::value_type () -> GType
{
  return gtk_shortcut_action_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GtkShortcutAction* object, bool take_copy) -> glib::RefPtr<gtk::ShortcutAction>
  {
    return glib::make_refptr_for_instance<gtk::ShortcutAction> (
        dynamic_cast<gtk::ShortcutAction*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ShortcutAction_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ShortcutAction_Class::class_init_function;

      gtype_ = gtk_shortcut_action_get_type ();
    }

    return *this;
  }

  auto
  ShortcutAction_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ShortcutAction_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ShortcutAction ((GtkShortcutAction*) object);
  }

  auto
  ShortcutAction::gobj_copy () -> GtkShortcutAction*
  {
    reference ();
    return gobj ();
  }

  ShortcutAction::ShortcutAction (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ShortcutAction::ShortcutAction (GtkShortcutAction* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  ShortcutAction::ShortcutAction (ShortcutAction&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  ShortcutAction::operator= (ShortcutAction&& src) noexcept -> ShortcutAction&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  ShortcutAction::~ShortcutAction () noexcept {}

  ShortcutAction::CppClassType ShortcutAction::shortcutaction_class_;

  auto
  ShortcutAction::get_type () -> GType
  {
    return shortcutaction_class_.init ().get_type ();
  }

  auto
  ShortcutAction::get_base_type () -> GType
  {
    return gtk_shortcut_action_get_type ();
  }

  ShortcutAction::ShortcutAction ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (shortcutaction_class_.init ()))
  {
  }

  auto
  ShortcutAction::parse_string (const glib::ustring& string) -> glib::RefPtr<ShortcutAction>
  {
    return glib::wrap (gtk_shortcut_action_parse_string (string.c_str ()));
  }

  auto
  ShortcutAction::to_string () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_shortcut_action_to_string (
            const_cast<GtkShortcutAction*> (gobj ())));
  }

  auto
  ShortcutAction::activate (Widget& widget,
                            Flags flags,
                            const glib::VariantBase& args) -> bool
  {
    return gtk_shortcut_action_activate (
        gobj (),
        static_cast<GtkShortcutActionFlags> (flags),
        (widget).gobj (),
        const_cast<GVariant*> ((args).gobj ()));
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkNothingAction* object, bool take_copy) -> glib::RefPtr<gtk::NothingAction>
  {
    return glib::make_refptr_for_instance<gtk::NothingAction> (
        dynamic_cast<gtk::NothingAction*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  NothingAction_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &NothingAction_Class::class_init_function;

      gtype_ = gtk_nothing_action_get_type ();
    }

    return *this;
  }

  auto
  NothingAction_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  NothingAction_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new NothingAction ((GtkNothingAction*) object);
  }

  auto
  NothingAction::gobj_copy () -> GtkNothingAction*
  {
    reference ();
    return gobj ();
  }

  NothingAction::NothingAction (const glib::ConstructParams& construct_params)
    : ShortcutAction (construct_params)
  {
  }

  NothingAction::NothingAction (GtkNothingAction* castitem)
    : ShortcutAction ((GtkShortcutAction*) (castitem))
  {
  }

  NothingAction::NothingAction (NothingAction&& src) noexcept
    : ShortcutAction (std::move (src))
  {
  }

  auto
  NothingAction::operator= (NothingAction&& src) noexcept -> NothingAction&
  {
    ShortcutAction::operator= (std::move (src));
    return *this;
  }

  NothingAction::~NothingAction () noexcept {}

  NothingAction::CppClassType NothingAction::nothingaction_class_;

  auto
  NothingAction::get_type () -> GType
  {
    return nothingaction_class_.init ().get_type ();
  }

  auto
  NothingAction::get_base_type () -> GType
  {
    return gtk_nothing_action_get_type ();
  }

  NothingAction::NothingAction ()
    : glib::ObjectBase (nullptr),
      ShortcutAction (glib::ConstructParams (nothingaction_class_.init ()))
  {
  }

  auto
  NothingAction::get () -> glib::RefPtr<NothingAction>
  {
    auto retvalue = glib::wrap (GTK_NOTHING_ACTION (gtk_nothing_action_get ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkCallbackAction* object, bool take_copy) -> glib::RefPtr<gtk::CallbackAction>
  {
    return glib::make_refptr_for_instance<gtk::CallbackAction> (
        dynamic_cast<gtk::CallbackAction*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  CallbackAction_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CallbackAction_Class::class_init_function;

      gtype_ = gtk_callback_action_get_type ();
    }

    return *this;
  }

  auto
  CallbackAction_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CallbackAction_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new CallbackAction ((GtkCallbackAction*) object);
  }

  auto
  CallbackAction::gobj_copy () -> GtkCallbackAction*
  {
    reference ();
    return gobj ();
  }

  CallbackAction::CallbackAction (const glib::ConstructParams& construct_params)
    : ShortcutAction (construct_params)
  {
  }

  CallbackAction::CallbackAction (GtkCallbackAction* castitem)
    : ShortcutAction ((GtkShortcutAction*) (castitem))
  {
  }

  CallbackAction::CallbackAction (CallbackAction&& src) noexcept
    : ShortcutAction (std::move (src))
  {
  }

  auto
  CallbackAction::operator= (CallbackAction&& src) noexcept -> CallbackAction&
  {
    ShortcutAction::operator= (std::move (src));
    return *this;
  }

  CallbackAction::~CallbackAction () noexcept {}

  CallbackAction::CppClassType CallbackAction::callbackaction_class_;

  auto
  CallbackAction::get_type () -> GType
  {
    return callbackaction_class_.init ().get_type ();
  }

  auto
  CallbackAction::get_base_type () -> GType
  {
    return gtk_callback_action_get_type ();
  }

  auto
  CallbackAction::create (const SlotShortcut& slot) -> glib::RefPtr<CallbackAction>
  {
    return glib::make_refptr_for_instance<CallbackAction> (
        new CallbackAction (slot));
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkMnemonicAction* object, bool take_copy) -> glib::RefPtr<gtk::MnemonicAction>
  {
    return glib::make_refptr_for_instance<gtk::MnemonicAction> (
        dynamic_cast<gtk::MnemonicAction*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  MnemonicAction_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MnemonicAction_Class::class_init_function;

      gtype_ = gtk_mnemonic_action_get_type ();
    }

    return *this;
  }

  auto
  MnemonicAction_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MnemonicAction_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MnemonicAction ((GtkMnemonicAction*) object);
  }

  auto
  MnemonicAction::gobj_copy () -> GtkMnemonicAction*
  {
    reference ();
    return gobj ();
  }

  MnemonicAction::MnemonicAction (const glib::ConstructParams& construct_params)
    : ShortcutAction (construct_params)
  {
  }

  MnemonicAction::MnemonicAction (GtkMnemonicAction* castitem)
    : ShortcutAction ((GtkShortcutAction*) (castitem))
  {
  }

  MnemonicAction::MnemonicAction (MnemonicAction&& src) noexcept
    : ShortcutAction (std::move (src))
  {
  }

  auto
  MnemonicAction::operator= (MnemonicAction&& src) noexcept -> MnemonicAction&
  {
    ShortcutAction::operator= (std::move (src));
    return *this;
  }

  MnemonicAction::~MnemonicAction () noexcept {}

  MnemonicAction::CppClassType MnemonicAction::mnemonicaction_class_;

  auto
  MnemonicAction::get_type () -> GType
  {
    return mnemonicaction_class_.init ().get_type ();
  }

  auto
  MnemonicAction::get_base_type () -> GType
  {
    return gtk_mnemonic_action_get_type ();
  }

  MnemonicAction::MnemonicAction ()
    : glib::ObjectBase (nullptr),
      ShortcutAction (glib::ConstructParams (mnemonicaction_class_.init ()))
  {
  }

  auto
  MnemonicAction::get () -> glib::RefPtr<MnemonicAction>
  {
    auto retvalue =
        glib::wrap (GTK_MNEMONIC_ACTION (gtk_mnemonic_action_get ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkActivateAction* object, bool take_copy) -> glib::RefPtr<gtk::ActivateAction>
  {
    return glib::make_refptr_for_instance<gtk::ActivateAction> (
        dynamic_cast<gtk::ActivateAction*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ActivateAction_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ActivateAction_Class::class_init_function;

      gtype_ = gtk_activate_action_get_type ();
    }

    return *this;
  }

  auto
  ActivateAction_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ActivateAction_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ActivateAction ((GtkActivateAction*) object);
  }

  auto
  ActivateAction::gobj_copy () -> GtkActivateAction*
  {
    reference ();
    return gobj ();
  }

  ActivateAction::ActivateAction (const glib::ConstructParams& construct_params)
    : ShortcutAction (construct_params)
  {
  }

  ActivateAction::ActivateAction (GtkActivateAction* castitem)
    : ShortcutAction ((GtkShortcutAction*) (castitem))
  {
  }

  ActivateAction::ActivateAction (ActivateAction&& src) noexcept
    : ShortcutAction (std::move (src))
  {
  }

  auto
  ActivateAction::operator= (ActivateAction&& src) noexcept -> ActivateAction&
  {
    ShortcutAction::operator= (std::move (src));
    return *this;
  }

  ActivateAction::~ActivateAction () noexcept {}

  ActivateAction::CppClassType ActivateAction::activateaction_class_;

  auto
  ActivateAction::get_type () -> GType
  {
    return activateaction_class_.init ().get_type ();
  }

  auto
  ActivateAction::get_base_type () -> GType
  {
    return gtk_activate_action_get_type ();
  }

  ActivateAction::ActivateAction ()
    : glib::ObjectBase (nullptr),
      ShortcutAction (glib::ConstructParams (activateaction_class_.init ()))
  {
  }

  auto
  ActivateAction::get () -> glib::RefPtr<ActivateAction>
  {
    auto retvalue =
        glib::wrap (GTK_ACTIVATE_ACTION (gtk_activate_action_get ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkSignalAction* object, bool take_copy) -> glib::RefPtr<gtk::SignalAction>
  {
    return glib::make_refptr_for_instance<gtk::SignalAction> (
        dynamic_cast<gtk::SignalAction*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  SignalAction_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SignalAction_Class::class_init_function;

      gtype_ = gtk_signal_action_get_type ();
    }

    return *this;
  }

  auto
  SignalAction_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SignalAction_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SignalAction ((GtkSignalAction*) object);
  }

  auto
  SignalAction::gobj_copy () -> GtkSignalAction*
  {
    reference ();
    return gobj ();
  }

  SignalAction::SignalAction (const glib::ConstructParams& construct_params)
    : ShortcutAction (construct_params)
  {
  }

  SignalAction::SignalAction (GtkSignalAction* castitem)
    : ShortcutAction ((GtkShortcutAction*) (castitem))
  {
  }

  SignalAction::SignalAction (SignalAction&& src) noexcept
    : ShortcutAction (std::move (src))
  {
  }

  auto
  SignalAction::operator= (SignalAction&& src) noexcept -> SignalAction&
  {
    ShortcutAction::operator= (std::move (src));
    return *this;
  }

  SignalAction::~SignalAction () noexcept {}

  SignalAction::CppClassType SignalAction::signalaction_class_;

  auto
  SignalAction::get_type () -> GType
  {
    return signalaction_class_.init ().get_type ();
  }

  auto
  SignalAction::get_base_type () -> GType
  {
    return gtk_signal_action_get_type ();
  }

  SignalAction::SignalAction (const glib::ustring& signal_name)
    : glib::ObjectBase (nullptr),
      ShortcutAction (glib::ConstructParams (signalaction_class_.init (),
                                             "signal_name",
                                             signal_name.c_str (),
                                             nullptr))
  {
  }

  auto
  SignalAction::create (const glib::ustring& signal_name) -> glib::RefPtr<SignalAction>
  {
    return glib::make_refptr_for_instance<SignalAction> (
        new SignalAction (signal_name));
  }

  auto
  SignalAction::get_signal_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_signal_action_get_signal_name (
            const_cast<GtkSignalAction*> (gobj ())));
  }

  auto
  SignalAction::property_signal_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "signal-name");
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkNamedAction* object, bool take_copy) -> glib::RefPtr<gtk::NamedAction>
  {
    return glib::make_refptr_for_instance<gtk::NamedAction> (
        dynamic_cast<gtk::NamedAction*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  NamedAction_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &NamedAction_Class::class_init_function;

      gtype_ = gtk_named_action_get_type ();
    }

    return *this;
  }

  auto
  NamedAction_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  NamedAction_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new NamedAction ((GtkNamedAction*) object);
  }

  auto
  NamedAction::gobj_copy () -> GtkNamedAction*
  {
    reference ();
    return gobj ();
  }

  NamedAction::NamedAction (const glib::ConstructParams& construct_params)
    : ShortcutAction (construct_params)
  {
  }

  NamedAction::NamedAction (GtkNamedAction* castitem)
    : ShortcutAction ((GtkShortcutAction*) (castitem))
  {
  }

  NamedAction::NamedAction (NamedAction&& src) noexcept
    : ShortcutAction (std::move (src))
  {
  }

  auto
  NamedAction::operator= (NamedAction&& src) noexcept -> NamedAction&
  {
    ShortcutAction::operator= (std::move (src));
    return *this;
  }

  NamedAction::~NamedAction () noexcept {}

  NamedAction::CppClassType NamedAction::namedaction_class_;

  auto
  NamedAction::get_type () -> GType
  {
    return namedaction_class_.init ().get_type ();
  }

  auto
  NamedAction::get_base_type () -> GType
  {
    return gtk_named_action_get_type ();
  }

  NamedAction::NamedAction (const glib::ustring& action_name)
    : glib::ObjectBase (nullptr),
      ShortcutAction (glib::ConstructParams (namedaction_class_.init (),
                                             "action_name",
                                             action_name.c_str (),
                                             nullptr))
  {
  }

  auto
  NamedAction::create (const glib::ustring& action_name) -> glib::RefPtr<NamedAction>
  {
    return glib::make_refptr_for_instance<NamedAction> (
        new NamedAction (action_name));
  }

  auto
  NamedAction::get_action_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_named_action_get_action_name (
            const_cast<GtkNamedAction*> (gobj ())));
  }

  auto
  NamedAction::property_action_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "action-name");
  }

} // namespace gtk
