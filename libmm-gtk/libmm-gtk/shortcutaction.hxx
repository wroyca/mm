// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTACTION_H
#define _GTKMM_SHORTCUTACTION_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutAction = struct _GtkShortcutAction;
using GtkShortcutActionClass = struct _GtkShortcutActionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ShortcutAction_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNothingAction = struct _GtkNothingAction;
using GtkNothingActionClass = struct _GtkNothingActionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API NothingAction_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCallbackAction = struct _GtkCallbackAction;
using GtkCallbackActionClass = struct _GtkCallbackActionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CallbackAction_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMnemonicAction = struct _GtkMnemonicAction;
using GtkMnemonicActionClass = struct _GtkMnemonicActionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API MnemonicAction_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkActivateAction = struct _GtkActivateAction;
using GtkActivateActionClass = struct _GtkActivateActionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ActivateAction_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSignalAction = struct _GtkSignalAction;
using GtkSignalActionClass = struct _GtkSignalActionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API SignalAction_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNamedAction = struct _GtkNamedAction;
using GtkNamedActionClass = struct _GtkNamedActionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API NamedAction_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API Widget;

  class GTKMM_API ShortcutAction : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ShortcutAction;
    using CppClassType = ShortcutAction_Class;
    using BaseObjectType = GtkShortcutAction;
    using BaseClassType = GtkShortcutActionClass;

    ShortcutAction (const ShortcutAction&) = delete;
    auto
    operator= (const ShortcutAction&) -> ShortcutAction& = delete;

  private:
    friend class ShortcutAction_Class;
    static CppClassType shortcutaction_class_;

  protected:
    explicit ShortcutAction (const Glib::ConstructParams& construct_params);
    explicit ShortcutAction (GtkShortcutAction* castitem);

#endif

  public:
    ShortcutAction (ShortcutAction&& src) noexcept;
    auto
    operator= (ShortcutAction&& src) noexcept -> ShortcutAction&;

    ~ShortcutAction () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkShortcutAction*
    {
      return reinterpret_cast<GtkShortcutAction*> (gobject_);
    }

    auto
    gobj () const -> const GtkShortcutAction*
    {
      return reinterpret_cast<GtkShortcutAction*> (gobject_);
    }

    auto
    gobj_copy () -> GtkShortcutAction*;

  private:
  protected:
    ShortcutAction ();

  public:
    enum class Flags
    {
      EXCLUSIVE = 1 << 0
    };

    static auto
    parse_string (const Glib::ustring& string) -> Glib::RefPtr<ShortcutAction>;

    auto
    to_string () const -> Glib::ustring;

    auto
    activate (Widget& widget,
              Flags flags = static_cast<Flags> (0),
              const Glib::VariantBase& args = {}) -> bool;

  public:
  public:
  protected:
  };

  class GTKMM_API NothingAction : public ShortcutAction
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = NothingAction;
    using CppClassType = NothingAction_Class;
    using BaseObjectType = GtkNothingAction;
    using BaseClassType = GtkNothingActionClass;

    NothingAction (const NothingAction&) = delete;
    auto
    operator= (const NothingAction&) -> NothingAction& = delete;

  private:
    friend class NothingAction_Class;
    static CppClassType nothingaction_class_;

  protected:
    explicit NothingAction (const Glib::ConstructParams& construct_params);
    explicit NothingAction (GtkNothingAction* castitem);

#endif

  public:
    NothingAction (NothingAction&& src) noexcept;
    auto
    operator= (NothingAction&& src) noexcept -> NothingAction&;

    ~NothingAction () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkNothingAction*
    {
      return reinterpret_cast<GtkNothingAction*> (gobject_);
    }

    auto
    gobj () const -> const GtkNothingAction*
    {
      return reinterpret_cast<GtkNothingAction*> (gobject_);
    }

    auto
    gobj_copy () -> GtkNothingAction*;

  private:
  protected:
    NothingAction ();

  public:
    static auto
    get () -> Glib::RefPtr<NothingAction>;

  public:
  public:
  protected:
  };

  class GTKMM_API CallbackAction : public ShortcutAction
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CallbackAction;
    using CppClassType = CallbackAction_Class;
    using BaseObjectType = GtkCallbackAction;
    using BaseClassType = GtkCallbackActionClass;

    CallbackAction (const CallbackAction&) = delete;
    auto
    operator= (const CallbackAction&) -> CallbackAction& = delete;

  private:
    friend class CallbackAction_Class;
    static CppClassType callbackaction_class_;

  protected:
    explicit CallbackAction (const Glib::ConstructParams& construct_params);
    explicit CallbackAction (GtkCallbackAction* castitem);

#endif

  public:
    CallbackAction (CallbackAction&& src) noexcept;
    auto
    operator= (CallbackAction&& src) noexcept -> CallbackAction&;

    ~CallbackAction () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCallbackAction*
    {
      return reinterpret_cast<GtkCallbackAction*> (gobject_);
    }

    auto
    gobj () const -> const GtkCallbackAction*
    {
      return reinterpret_cast<GtkCallbackAction*> (gobject_);
    }

    auto
    gobj_copy () -> GtkCallbackAction*;

  private:
  public:
    using SlotShortcut = sigc::slot<bool (Widget&, const Glib::VariantBase&)>;

    static auto
    create (const SlotShortcut& slot) -> Glib::RefPtr<CallbackAction>;

  protected:
    explicit CallbackAction (const SlotShortcut& slot);

  public:
  public:
  protected:
  };

  class GTKMM_API MnemonicAction : public ShortcutAction
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MnemonicAction;
    using CppClassType = MnemonicAction_Class;
    using BaseObjectType = GtkMnemonicAction;
    using BaseClassType = GtkMnemonicActionClass;

    MnemonicAction (const MnemonicAction&) = delete;
    auto
    operator= (const MnemonicAction&) -> MnemonicAction& = delete;

  private:
    friend class MnemonicAction_Class;
    static CppClassType mnemonicaction_class_;

  protected:
    explicit MnemonicAction (const Glib::ConstructParams& construct_params);
    explicit MnemonicAction (GtkMnemonicAction* castitem);

#endif

  public:
    MnemonicAction (MnemonicAction&& src) noexcept;
    auto
    operator= (MnemonicAction&& src) noexcept -> MnemonicAction&;

    ~MnemonicAction () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkMnemonicAction*
    {
      return reinterpret_cast<GtkMnemonicAction*> (gobject_);
    }

    auto
    gobj () const -> const GtkMnemonicAction*
    {
      return reinterpret_cast<GtkMnemonicAction*> (gobject_);
    }

    auto
    gobj_copy () -> GtkMnemonicAction*;

  private:
  protected:
    MnemonicAction ();

  public:
    static auto
    get () -> Glib::RefPtr<MnemonicAction>;

  public:
  public:
  protected:
  };

  class GTKMM_API ActivateAction : public ShortcutAction
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ActivateAction;
    using CppClassType = ActivateAction_Class;
    using BaseObjectType = GtkActivateAction;
    using BaseClassType = GtkActivateActionClass;

    ActivateAction (const ActivateAction&) = delete;
    auto
    operator= (const ActivateAction&) -> ActivateAction& = delete;

  private:
    friend class ActivateAction_Class;
    static CppClassType activateaction_class_;

  protected:
    explicit ActivateAction (const Glib::ConstructParams& construct_params);
    explicit ActivateAction (GtkActivateAction* castitem);

#endif

  public:
    ActivateAction (ActivateAction&& src) noexcept;
    auto
    operator= (ActivateAction&& src) noexcept -> ActivateAction&;

    ~ActivateAction () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkActivateAction*
    {
      return reinterpret_cast<GtkActivateAction*> (gobject_);
    }

    auto
    gobj () const -> const GtkActivateAction*
    {
      return reinterpret_cast<GtkActivateAction*> (gobject_);
    }

    auto
    gobj_copy () -> GtkActivateAction*;

  private:
  protected:
    ActivateAction ();

  public:
    static auto
    get () -> Glib::RefPtr<ActivateAction>;

  public:
  public:
  protected:
  };

  class GTKMM_API SignalAction : public ShortcutAction
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SignalAction;
    using CppClassType = SignalAction_Class;
    using BaseObjectType = GtkSignalAction;
    using BaseClassType = GtkSignalActionClass;

    SignalAction (const SignalAction&) = delete;
    auto
    operator= (const SignalAction&) -> SignalAction& = delete;

  private:
    friend class SignalAction_Class;
    static CppClassType signalaction_class_;

  protected:
    explicit SignalAction (const Glib::ConstructParams& construct_params);
    explicit SignalAction (GtkSignalAction* castitem);

#endif

  public:
    SignalAction (SignalAction&& src) noexcept;
    auto
    operator= (SignalAction&& src) noexcept -> SignalAction&;

    ~SignalAction () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSignalAction*
    {
      return reinterpret_cast<GtkSignalAction*> (gobject_);
    }

    auto
    gobj () const -> const GtkSignalAction*
    {
      return reinterpret_cast<GtkSignalAction*> (gobject_);
    }

    auto
    gobj_copy () -> GtkSignalAction*;

  private:
  protected:
    explicit SignalAction (const Glib::ustring& signal_name);

  public:
    static auto
    create (const Glib::ustring& signal_name) -> Glib::RefPtr<SignalAction>;

    auto
    get_signal_name () const -> Glib::ustring;

    auto
    property_signal_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

  class GTKMM_API NamedAction : public ShortcutAction
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = NamedAction;
    using CppClassType = NamedAction_Class;
    using BaseObjectType = GtkNamedAction;
    using BaseClassType = GtkNamedActionClass;

    NamedAction (const NamedAction&) = delete;
    auto
    operator= (const NamedAction&) -> NamedAction& = delete;

  private:
    friend class NamedAction_Class;
    static CppClassType namedaction_class_;

  protected:
    explicit NamedAction (const Glib::ConstructParams& construct_params);
    explicit NamedAction (GtkNamedAction* castitem);

#endif

  public:
    NamedAction (NamedAction&& src) noexcept;
    auto
    operator= (NamedAction&& src) noexcept -> NamedAction&;

    ~NamedAction () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkNamedAction*
    {
      return reinterpret_cast<GtkNamedAction*> (gobject_);
    }

    auto
    gobj () const -> const GtkNamedAction*
    {
      return reinterpret_cast<GtkNamedAction*> (gobject_);
    }

    auto
    gobj_copy () -> GtkNamedAction*;

  private:
  protected:
    explicit NamedAction (const Glib::ustring& action_name);

  public:
    static auto
    create (const Glib::ustring& action_name) -> Glib::RefPtr<NamedAction>;

    auto
    get_action_name () const -> Glib::ustring;

    auto
    property_action_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Gtk
{

  inline auto
  operator| (ShortcutAction::Flags lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags
  {
    return static_cast<ShortcutAction::Flags> (static_cast<unsigned> (lhs) |
                                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (ShortcutAction::Flags lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags
  {
    return static_cast<ShortcutAction::Flags> (static_cast<unsigned> (lhs) &
                                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (ShortcutAction::Flags lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags
  {
    return static_cast<ShortcutAction::Flags> (static_cast<unsigned> (lhs) ^
                                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(ShortcutAction::Flags flags) -> ShortcutAction::Flags
  {
    return static_cast<ShortcutAction::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (ShortcutAction::Flags& lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags&
  {
    return (lhs = static_cast<ShortcutAction::Flags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (ShortcutAction::Flags& lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags&
  {
    return (lhs = static_cast<ShortcutAction::Flags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (ShortcutAction::Flags& lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags&
  {
    return (lhs = static_cast<ShortcutAction::Flags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::ShortcutAction::Flags>
    : public Glib::Value_Flags<Gtk::ShortcutAction::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkShortcutAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ShortcutAction>;
} // namespace Glib

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkNothingAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NothingAction>;
} // namespace Glib

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkCallbackAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CallbackAction>;
} // namespace Glib

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkMnemonicAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MnemonicAction>;
} // namespace Glib

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkActivateAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ActivateAction>;
} // namespace Glib

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkSignalAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SignalAction>;
} // namespace Glib

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkNamedAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NamedAction>;
} // namespace Glib

#endif
