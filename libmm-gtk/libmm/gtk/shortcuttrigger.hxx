// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTTRIGGER_H
#define _GTKMM_SHORTCUTTRIGGER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/display.hxx>
#include <libmm/gdk/enums.hxx>
#include <libmm/gdk/event.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutTrigger = struct _GtkShortcutTrigger;
using GtkShortcutTriggerClass = struct _GtkShortcutTriggerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ShortcutTrigger_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNeverTrigger = struct _GtkNeverTrigger;
using GtkNeverTriggerClass = struct _GtkNeverTriggerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT NeverTrigger_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkKeyvalTrigger = struct _GtkKeyvalTrigger;
using GtkKeyvalTriggerClass = struct _GtkKeyvalTriggerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT KeyvalTrigger_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMnemonicTrigger = struct _GtkMnemonicTrigger;
using GtkMnemonicTriggerClass = struct _GtkMnemonicTriggerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT MnemonicTrigger_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAlternativeTrigger = struct _GtkAlternativeTrigger;
using GtkAlternativeTriggerClass = struct _GtkAlternativeTriggerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT AlternativeTrigger_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutTrigger : public glib::Object
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
    explicit ShortcutTrigger (const glib::ConstructParams& construct_params);
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
    parse_string (const glib::ustring& string) -> glib::RefPtr<ShortcutTrigger>;

    auto
    to_string () const -> glib::ustring;

    auto
    to_label (const glib::RefPtr<const gdk::Display>& display) const
        -> glib::ustring;

    auto
    equal (const glib::RefPtr<const ShortcutTrigger>& trigger2) const -> bool;

    auto
    compare (const glib::RefPtr<const ShortcutTrigger>& trigger2) const -> int;

    auto
    trigger (const glib::RefPtr<const gdk::Event>& event,
             bool enable_mnemonics) const -> gdk::KeyMatch;

  public:
  public:
  protected:
  };

  class LIBMM_GTK_SYMEXPORT NeverTrigger : public ShortcutTrigger
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
    explicit NeverTrigger (const glib::ConstructParams& construct_params);
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
    get () -> glib::RefPtr<NeverTrigger>;

  public:
  public:
  protected:
  };

  class LIBMM_GTK_SYMEXPORT KeyvalTrigger : public ShortcutTrigger
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
    explicit KeyvalTrigger (const glib::ConstructParams& construct_params);
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
    explicit KeyvalTrigger (guint keyval, gdk::ModifierType modifiers);

  public:
    static auto
    create (guint keyval,
            gdk::ModifierType modifiers = static_cast<gdk::ModifierType> (0))
        -> glib::RefPtr<KeyvalTrigger>;

    auto
    get_keyval () const -> guint;

    auto
    get_modifiers () const -> gdk::ModifierType;

    auto
    property_keyval () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_modifiers () const
        -> glib::PropertyProxy_ReadOnly<gdk::ModifierType>;

  public:
  public:
  protected:
  };

  class LIBMM_GTK_SYMEXPORT MnemonicTrigger : public ShortcutTrigger
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
    explicit MnemonicTrigger (const glib::ConstructParams& construct_params);
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
    create (guint keyval) -> glib::RefPtr<MnemonicTrigger>;

    auto
    get_keyval () const -> guint;

    auto
    property_keyval () const -> glib::PropertyProxy_ReadOnly<guint>;

  public:
  public:
  protected:
  };

  class LIBMM_GTK_SYMEXPORT AlternativeTrigger : public ShortcutTrigger
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
    explicit AlternativeTrigger (const glib::ConstructParams& construct_params);
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
        const glib::RefPtr<const ShortcutTrigger>& first,
        const glib::RefPtr<const ShortcutTrigger>& second);

  public:
    static auto
    create (const glib::RefPtr<const ShortcutTrigger>& first,
            const glib::RefPtr<const ShortcutTrigger>& second)
        -> glib::RefPtr<AlternativeTrigger>;

    auto
    get_first () const -> glib::RefPtr<const ShortcutTrigger>;

    auto
    get_second () const -> glib::RefPtr<const ShortcutTrigger>;

    auto
    property_first () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<const ShortcutTrigger>>;

    auto
    property_second () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<const ShortcutTrigger>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkShortcutTrigger* object, bool take_copy = false) -> glib::RefPtr<gtk::ShortcutTrigger>;
} // namespace glib

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkNeverTrigger* object, bool take_copy = false) -> glib::RefPtr<gtk::NeverTrigger>;
} // namespace glib

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkKeyvalTrigger* object, bool take_copy = false) -> glib::RefPtr<gtk::KeyvalTrigger>;
} // namespace glib

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkMnemonicTrigger* object, bool take_copy = false) -> glib::RefPtr<gtk::MnemonicTrigger>;
} // namespace glib

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAlternativeTrigger* object, bool take_copy = false) -> glib::RefPtr<gtk::AlternativeTrigger>;
} // namespace glib

#endif
