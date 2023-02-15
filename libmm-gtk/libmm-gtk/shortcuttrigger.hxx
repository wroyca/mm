// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTTRIGGER_H
#define _GTKMM_SHORTCUTTRIGGER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/display.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/event.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutTrigger = struct _GtkShortcutTrigger;
using GtkShortcutTriggerClass = struct _GtkShortcutTriggerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ShortcutTrigger_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNeverTrigger = struct _GtkNeverTrigger;
using GtkNeverTriggerClass = struct _GtkNeverTriggerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API NeverTrigger_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkKeyvalTrigger = struct _GtkKeyvalTrigger;
using GtkKeyvalTriggerClass = struct _GtkKeyvalTriggerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API KeyvalTrigger_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMnemonicTrigger = struct _GtkMnemonicTrigger;
using GtkMnemonicTriggerClass = struct _GtkMnemonicTriggerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API MnemonicTrigger_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAlternativeTrigger = struct _GtkAlternativeTrigger;
using GtkAlternativeTriggerClass = struct _GtkAlternativeTriggerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API AlternativeTrigger_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ShortcutTrigger : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ShortcutTrigger;
    using CppClassType = ShortcutTrigger_Class;
    using BaseObjectType = GtkShortcutTrigger;
    using BaseClassType = GtkShortcutTriggerClass;

    ShortcutTrigger (const ShortcutTrigger&) = delete;
    auto
    operator= (const ShortcutTrigger&) -> ShortcutTrigger& = delete;

  private:
    friend class ShortcutTrigger_Class;
    static CppClassType shortcuttrigger_class_;

  protected:
    explicit ShortcutTrigger (const Glib::ConstructParams& construct_params);
    explicit ShortcutTrigger (GtkShortcutTrigger* castitem);

#endif

  public:
    ShortcutTrigger (ShortcutTrigger&& src) noexcept;
    auto
    operator= (ShortcutTrigger&& src) noexcept -> ShortcutTrigger&;

    ~ShortcutTrigger () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkShortcutTrigger*
    {
      return reinterpret_cast<GtkShortcutTrigger*> (gobject_);
    }

    auto
    gobj () const -> const GtkShortcutTrigger*
    {
      return reinterpret_cast<GtkShortcutTrigger*> (gobject_);
    }

    auto
    gobj_copy () -> GtkShortcutTrigger*;

  private:
  protected:
    ShortcutTrigger ();

  public:
    static auto
    parse_string (const Glib::ustring& string) -> Glib::RefPtr<ShortcutTrigger>;

    auto
    to_string () const -> Glib::ustring;

    auto
    to_label (const Glib::RefPtr<const Gdk::Display>& display) const
        -> Glib::ustring;

    auto
    equal (const Glib::RefPtr<const ShortcutTrigger>& trigger2) const -> bool;

    auto
    compare (const Glib::RefPtr<const ShortcutTrigger>& trigger2) const -> int;

    auto
    trigger (const Glib::RefPtr<const Gdk::Event>& event,
             bool enable_mnemonics) const -> Gdk::KeyMatch;

  public:
  public:
  protected:
  };

  class GTKMM_API NeverTrigger : public ShortcutTrigger
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = NeverTrigger;
    using CppClassType = NeverTrigger_Class;
    using BaseObjectType = GtkNeverTrigger;
    using BaseClassType = GtkNeverTriggerClass;

    NeverTrigger (const NeverTrigger&) = delete;
    auto
    operator= (const NeverTrigger&) -> NeverTrigger& = delete;

  private:
    friend class NeverTrigger_Class;
    static CppClassType nevertrigger_class_;

  protected:
    explicit NeverTrigger (const Glib::ConstructParams& construct_params);
    explicit NeverTrigger (GtkNeverTrigger* castitem);

#endif

  public:
    NeverTrigger (NeverTrigger&& src) noexcept;
    auto
    operator= (NeverTrigger&& src) noexcept -> NeverTrigger&;

    ~NeverTrigger () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkNeverTrigger*
    {
      return reinterpret_cast<GtkNeverTrigger*> (gobject_);
    }

    auto
    gobj () const -> const GtkNeverTrigger*
    {
      return reinterpret_cast<GtkNeverTrigger*> (gobject_);
    }

    auto
    gobj_copy () -> GtkNeverTrigger*;

  private:
  protected:
    NeverTrigger ();

  public:
    static auto
    get () -> Glib::RefPtr<NeverTrigger>;

  public:
  public:
  protected:
  };

  class GTKMM_API KeyvalTrigger : public ShortcutTrigger
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = KeyvalTrigger;
    using CppClassType = KeyvalTrigger_Class;
    using BaseObjectType = GtkKeyvalTrigger;
    using BaseClassType = GtkKeyvalTriggerClass;

    KeyvalTrigger (const KeyvalTrigger&) = delete;
    auto
    operator= (const KeyvalTrigger&) -> KeyvalTrigger& = delete;

  private:
    friend class KeyvalTrigger_Class;
    static CppClassType keyvaltrigger_class_;

  protected:
    explicit KeyvalTrigger (const Glib::ConstructParams& construct_params);
    explicit KeyvalTrigger (GtkKeyvalTrigger* castitem);

#endif

  public:
    KeyvalTrigger (KeyvalTrigger&& src) noexcept;
    auto
    operator= (KeyvalTrigger&& src) noexcept -> KeyvalTrigger&;

    ~KeyvalTrigger () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkKeyvalTrigger*
    {
      return reinterpret_cast<GtkKeyvalTrigger*> (gobject_);
    }

    auto
    gobj () const -> const GtkKeyvalTrigger*
    {
      return reinterpret_cast<GtkKeyvalTrigger*> (gobject_);
    }

    auto
    gobj_copy () -> GtkKeyvalTrigger*;

  private:
  protected:
    explicit KeyvalTrigger (guint keyval, Gdk::ModifierType modifiers);

  public:
    static auto
    create (guint keyval,
            Gdk::ModifierType modifiers = static_cast<Gdk::ModifierType> (0))
        -> Glib::RefPtr<KeyvalTrigger>;

    auto
    get_keyval () const -> guint;

    auto
    get_modifiers () const -> Gdk::ModifierType;

    auto
    property_keyval () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_modifiers () const
        -> Glib::PropertyProxy_ReadOnly<Gdk::ModifierType>;

  public:
  public:
  protected:
  };

  class GTKMM_API MnemonicTrigger : public ShortcutTrigger
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MnemonicTrigger;
    using CppClassType = MnemonicTrigger_Class;
    using BaseObjectType = GtkMnemonicTrigger;
    using BaseClassType = GtkMnemonicTriggerClass;

    MnemonicTrigger (const MnemonicTrigger&) = delete;
    auto
    operator= (const MnemonicTrigger&) -> MnemonicTrigger& = delete;

  private:
    friend class MnemonicTrigger_Class;
    static CppClassType mnemonictrigger_class_;

  protected:
    explicit MnemonicTrigger (const Glib::ConstructParams& construct_params);
    explicit MnemonicTrigger (GtkMnemonicTrigger* castitem);

#endif

  public:
    MnemonicTrigger (MnemonicTrigger&& src) noexcept;
    auto
    operator= (MnemonicTrigger&& src) noexcept -> MnemonicTrigger&;

    ~MnemonicTrigger () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkMnemonicTrigger*
    {
      return reinterpret_cast<GtkMnemonicTrigger*> (gobject_);
    }

    auto
    gobj () const -> const GtkMnemonicTrigger*
    {
      return reinterpret_cast<GtkMnemonicTrigger*> (gobject_);
    }

    auto
    gobj_copy () -> GtkMnemonicTrigger*;

  private:
  protected:
    explicit MnemonicTrigger (guint keyval);

  public:
    static auto
    create (guint keyval) -> Glib::RefPtr<MnemonicTrigger>;

    auto
    get_keyval () const -> guint;

    auto
    property_keyval () const -> Glib::PropertyProxy_ReadOnly<guint>;

  public:
  public:
  protected:
  };

  class GTKMM_API AlternativeTrigger : public ShortcutTrigger
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AlternativeTrigger;
    using CppClassType = AlternativeTrigger_Class;
    using BaseObjectType = GtkAlternativeTrigger;
    using BaseClassType = GtkAlternativeTriggerClass;

    AlternativeTrigger (const AlternativeTrigger&) = delete;
    auto
    operator= (const AlternativeTrigger&) -> AlternativeTrigger& = delete;

  private:
    friend class AlternativeTrigger_Class;
    static CppClassType alternativetrigger_class_;

  protected:
    explicit AlternativeTrigger (const Glib::ConstructParams& construct_params);
    explicit AlternativeTrigger (GtkAlternativeTrigger* castitem);

#endif

  public:
    AlternativeTrigger (AlternativeTrigger&& src) noexcept;
    auto
    operator= (AlternativeTrigger&& src) noexcept -> AlternativeTrigger&;

    ~AlternativeTrigger () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkAlternativeTrigger*
    {
      return reinterpret_cast<GtkAlternativeTrigger*> (gobject_);
    }

    auto
    gobj () const -> const GtkAlternativeTrigger*
    {
      return reinterpret_cast<GtkAlternativeTrigger*> (gobject_);
    }

    auto
    gobj_copy () -> GtkAlternativeTrigger*;

  private:
  protected:
    explicit AlternativeTrigger (
        const Glib::RefPtr<const ShortcutTrigger>& first,
        const Glib::RefPtr<const ShortcutTrigger>& second);

  public:
    static auto
    create (const Glib::RefPtr<const ShortcutTrigger>& first,
            const Glib::RefPtr<const ShortcutTrigger>& second)
        -> Glib::RefPtr<AlternativeTrigger>;

    auto
    get_first () const -> Glib::RefPtr<const ShortcutTrigger>;

    auto
    get_second () const -> Glib::RefPtr<const ShortcutTrigger>;

    auto
    property_first () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<const ShortcutTrigger>>;

    auto
    property_second () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<const ShortcutTrigger>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkShortcutTrigger* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ShortcutTrigger>;
} // namespace Glib

namespace Glib
{
  GTKMM_API auto
  wrap (GtkNeverTrigger* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NeverTrigger>;
} // namespace Glib

namespace Glib
{
  GTKMM_API auto
  wrap (GtkKeyvalTrigger* object, bool take_copy = false) -> Glib::RefPtr<Gtk::KeyvalTrigger>;
} // namespace Glib

namespace Glib
{
  GTKMM_API auto
  wrap (GtkMnemonicTrigger* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MnemonicTrigger>;
} // namespace Glib

namespace Glib
{
  GTKMM_API auto
  wrap (GtkAlternativeTrigger* object, bool take_copy = false) -> Glib::RefPtr<Gtk::AlternativeTrigger>;
} // namespace Glib

#endif
