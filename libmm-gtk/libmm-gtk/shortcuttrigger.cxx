// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/shortcuttrigger.hxx>
#include <libmm-gtk/shortcuttrigger_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkShortcutTrigger* object, bool take_copy) -> Glib::RefPtr<Gtk::ShortcutTrigger>
  {
    return Glib::make_refptr_for_instance<Gtk::ShortcutTrigger> (
        dynamic_cast<Gtk::ShortcutTrigger*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ShortcutTrigger_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ShortcutTrigger_Class::class_init_function;

      gtype_ = gtk_shortcut_trigger_get_type ();
    }

    return *this;
  }

  auto
  ShortcutTrigger_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ShortcutTrigger_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ShortcutTrigger ((GtkShortcutTrigger*) object);
  }

  auto
  ShortcutTrigger::gobj_copy () -> GtkShortcutTrigger*
  {
    reference ();
    return gobj ();
  }

  ShortcutTrigger::ShortcutTrigger (
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  ShortcutTrigger::ShortcutTrigger (GtkShortcutTrigger* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  ShortcutTrigger::ShortcutTrigger (ShortcutTrigger&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  ShortcutTrigger::operator= (ShortcutTrigger&& src) noexcept -> ShortcutTrigger&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  ShortcutTrigger::~ShortcutTrigger () noexcept {}

  ShortcutTrigger::CppClassType ShortcutTrigger::shortcuttrigger_class_;

  auto
  ShortcutTrigger::get_type () -> GType
  {
    return shortcuttrigger_class_.init ().get_type ();
  }

  auto
  ShortcutTrigger::get_base_type () -> GType
  {
    return gtk_shortcut_trigger_get_type ();
  }

  ShortcutTrigger::ShortcutTrigger ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (shortcuttrigger_class_.init ()))
  {
  }

  auto
  ShortcutTrigger::parse_string (const Glib::ustring& string) -> Glib::RefPtr<ShortcutTrigger>
  {
    return Glib::wrap (gtk_shortcut_trigger_parse_string (string.c_str ()));
  }

  auto
  ShortcutTrigger::to_string () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_shortcut_trigger_to_string (
            const_cast<GtkShortcutTrigger*> (gobj ())));
  }

  auto
  ShortcutTrigger::to_label (
      const Glib::RefPtr<const Gdk::Display>& display) const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_shortcut_trigger_to_label (
            const_cast<GtkShortcutTrigger*> (gobj ()),
            const_cast<GdkDisplay*> (Glib::unwrap (display))));
  }

  auto
  ShortcutTrigger::equal (
      const Glib::RefPtr<const ShortcutTrigger>& trigger2) const -> bool
  {
    return gtk_shortcut_trigger_equal (
        const_cast<GtkShortcutTrigger*> (gobj ()),
        Glib::unwrap (trigger2));
  }

  auto
  ShortcutTrigger::compare (
      const Glib::RefPtr<const ShortcutTrigger>& trigger2) const -> int
  {
    return gtk_shortcut_trigger_compare (
        const_cast<GtkShortcutTrigger*> (gobj ()),
        Glib::unwrap (trigger2));
  }

  auto
  ShortcutTrigger::trigger (const Glib::RefPtr<const Gdk::Event>& event,
                            bool enable_mnemonics) const -> Gdk::KeyMatch
  {
    return static_cast<Gdk::KeyMatch> (gtk_shortcut_trigger_trigger (
        const_cast<GtkShortcutTrigger*> (gobj ()),
        const_cast<GdkEvent*> (Glib::unwrap (event)),
        static_cast<int> (enable_mnemonics)));
  }

} // namespace Gtk

namespace Glib
{

  auto
  wrap (GtkNeverTrigger* object, bool take_copy) -> Glib::RefPtr<Gtk::NeverTrigger>
  {
    return Glib::make_refptr_for_instance<Gtk::NeverTrigger> (
        dynamic_cast<Gtk::NeverTrigger*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  NeverTrigger_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &NeverTrigger_Class::class_init_function;

      gtype_ = gtk_never_trigger_get_type ();
    }

    return *this;
  }

  auto
  NeverTrigger_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  NeverTrigger_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new NeverTrigger ((GtkNeverTrigger*) object);
  }

  auto
  NeverTrigger::gobj_copy () -> GtkNeverTrigger*
  {
    reference ();
    return gobj ();
  }

  NeverTrigger::NeverTrigger (const Glib::ConstructParams& construct_params)
    : ShortcutTrigger (construct_params)
  {
  }

  NeverTrigger::NeverTrigger (GtkNeverTrigger* castitem)
    : ShortcutTrigger ((GtkShortcutTrigger*) (castitem))
  {
  }

  NeverTrigger::NeverTrigger (NeverTrigger&& src) noexcept
    : ShortcutTrigger (std::move (src))
  {
  }

  auto
  NeverTrigger::operator= (NeverTrigger&& src) noexcept -> NeverTrigger&
  {
    ShortcutTrigger::operator= (std::move (src));
    return *this;
  }

  NeverTrigger::~NeverTrigger () noexcept {}

  NeverTrigger::CppClassType NeverTrigger::nevertrigger_class_;

  auto
  NeverTrigger::get_type () -> GType
  {
    return nevertrigger_class_.init ().get_type ();
  }

  auto
  NeverTrigger::get_base_type () -> GType
  {
    return gtk_never_trigger_get_type ();
  }

  NeverTrigger::NeverTrigger ()
    : Glib::ObjectBase (nullptr),
      ShortcutTrigger (Glib::ConstructParams (nevertrigger_class_.init ()))
  {
  }

  auto
  NeverTrigger::get () -> Glib::RefPtr<NeverTrigger>
  {
    auto retvalue = Glib::wrap (GTK_NEVER_TRIGGER (gtk_never_trigger_get ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

} // namespace Gtk

namespace Glib
{

  auto
  wrap (GtkKeyvalTrigger* object, bool take_copy) -> Glib::RefPtr<Gtk::KeyvalTrigger>
  {
    return Glib::make_refptr_for_instance<Gtk::KeyvalTrigger> (
        dynamic_cast<Gtk::KeyvalTrigger*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  KeyvalTrigger_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &KeyvalTrigger_Class::class_init_function;

      gtype_ = gtk_keyval_trigger_get_type ();
    }

    return *this;
  }

  auto
  KeyvalTrigger_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  KeyvalTrigger_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new KeyvalTrigger ((GtkKeyvalTrigger*) object);
  }

  auto
  KeyvalTrigger::gobj_copy () -> GtkKeyvalTrigger*
  {
    reference ();
    return gobj ();
  }

  KeyvalTrigger::KeyvalTrigger (const Glib::ConstructParams& construct_params)
    : ShortcutTrigger (construct_params)
  {
  }

  KeyvalTrigger::KeyvalTrigger (GtkKeyvalTrigger* castitem)
    : ShortcutTrigger ((GtkShortcutTrigger*) (castitem))
  {
  }

  KeyvalTrigger::KeyvalTrigger (KeyvalTrigger&& src) noexcept
    : ShortcutTrigger (std::move (src))
  {
  }

  auto
  KeyvalTrigger::operator= (KeyvalTrigger&& src) noexcept -> KeyvalTrigger&
  {
    ShortcutTrigger::operator= (std::move (src));
    return *this;
  }

  KeyvalTrigger::~KeyvalTrigger () noexcept {}

  KeyvalTrigger::CppClassType KeyvalTrigger::keyvaltrigger_class_;

  auto
  KeyvalTrigger::get_type () -> GType
  {
    return keyvaltrigger_class_.init ().get_type ();
  }

  auto
  KeyvalTrigger::get_base_type () -> GType
  {
    return gtk_keyval_trigger_get_type ();
  }

  KeyvalTrigger::KeyvalTrigger (guint keyval, Gdk::ModifierType modifiers)
    : Glib::ObjectBase (nullptr),
      ShortcutTrigger (
          Glib::ConstructParams (keyvaltrigger_class_.init (),
                                 "keyval",
                                 keyval,
                                 "modifiers",
                                 static_cast<GdkModifierType> (modifiers),
                                 nullptr))
  {
  }

  auto
  KeyvalTrigger::create (guint keyval, Gdk::ModifierType modifiers) -> Glib::RefPtr<KeyvalTrigger>
  {
    return Glib::make_refptr_for_instance<KeyvalTrigger> (
        new KeyvalTrigger (keyval, modifiers));
  }

  auto
  KeyvalTrigger::get_keyval () const -> guint
  {
    return gtk_keyval_trigger_get_keyval (
        const_cast<GtkKeyvalTrigger*> (gobj ()));
  }

  auto
  KeyvalTrigger::get_modifiers () const -> Gdk::ModifierType
  {
    return static_cast<Gdk::ModifierType> (gtk_keyval_trigger_get_modifiers (
        const_cast<GtkKeyvalTrigger*> (gobj ())));
  }

  auto
  KeyvalTrigger::property_keyval () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "keyval");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::ModifierType>::value,
      "Type Gdk::ModifierType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  KeyvalTrigger::property_modifiers () const -> Glib::PropertyProxy_ReadOnly<Gdk::ModifierType>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::ModifierType> (this, "modifiers");
  }

} // namespace Gtk

namespace Glib
{

  auto
  wrap (GtkMnemonicTrigger* object, bool take_copy) -> Glib::RefPtr<Gtk::MnemonicTrigger>
  {
    return Glib::make_refptr_for_instance<Gtk::MnemonicTrigger> (
        dynamic_cast<Gtk::MnemonicTrigger*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  MnemonicTrigger_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MnemonicTrigger_Class::class_init_function;

      gtype_ = gtk_mnemonic_trigger_get_type ();
    }

    return *this;
  }

  auto
  MnemonicTrigger_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MnemonicTrigger_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MnemonicTrigger ((GtkMnemonicTrigger*) object);
  }

  auto
  MnemonicTrigger::gobj_copy () -> GtkMnemonicTrigger*
  {
    reference ();
    return gobj ();
  }

  MnemonicTrigger::MnemonicTrigger (
      const Glib::ConstructParams& construct_params)
    : ShortcutTrigger (construct_params)
  {
  }

  MnemonicTrigger::MnemonicTrigger (GtkMnemonicTrigger* castitem)
    : ShortcutTrigger ((GtkShortcutTrigger*) (castitem))
  {
  }

  MnemonicTrigger::MnemonicTrigger (MnemonicTrigger&& src) noexcept
    : ShortcutTrigger (std::move (src))
  {
  }

  auto
  MnemonicTrigger::operator= (MnemonicTrigger&& src) noexcept -> MnemonicTrigger&
  {
    ShortcutTrigger::operator= (std::move (src));
    return *this;
  }

  MnemonicTrigger::~MnemonicTrigger () noexcept {}

  MnemonicTrigger::CppClassType MnemonicTrigger::mnemonictrigger_class_;

  auto
  MnemonicTrigger::get_type () -> GType
  {
    return mnemonictrigger_class_.init ().get_type ();
  }

  auto
  MnemonicTrigger::get_base_type () -> GType
  {
    return gtk_mnemonic_trigger_get_type ();
  }

  MnemonicTrigger::MnemonicTrigger (guint keyval)
    : Glib::ObjectBase (nullptr),
      ShortcutTrigger (Glib::ConstructParams (mnemonictrigger_class_.init (),
                                              "keyval",
                                              keyval,
                                              nullptr))
  {
  }

  auto
  MnemonicTrigger::create (guint keyval) -> Glib::RefPtr<MnemonicTrigger>
  {
    return Glib::make_refptr_for_instance<MnemonicTrigger> (
        new MnemonicTrigger (keyval));
  }

  auto
  MnemonicTrigger::get_keyval () const -> guint
  {
    return gtk_mnemonic_trigger_get_keyval (
        const_cast<GtkMnemonicTrigger*> (gobj ()));
  }

  auto
  MnemonicTrigger::property_keyval () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "keyval");
  }

} // namespace Gtk

namespace Glib
{

  auto
  wrap (GtkAlternativeTrigger* object, bool take_copy) -> Glib::RefPtr<Gtk::AlternativeTrigger>
  {
    return Glib::make_refptr_for_instance<Gtk::AlternativeTrigger> (
        dynamic_cast<Gtk::AlternativeTrigger*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  AlternativeTrigger_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AlternativeTrigger_Class::class_init_function;

      gtype_ = gtk_alternative_trigger_get_type ();
    }

    return *this;
  }

  auto
  AlternativeTrigger_Class::class_init_function (void* g_class,
                                                 void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AlternativeTrigger_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new AlternativeTrigger ((GtkAlternativeTrigger*) object);
  }

  auto
  AlternativeTrigger::gobj_copy () -> GtkAlternativeTrigger*
  {
    reference ();
    return gobj ();
  }

  AlternativeTrigger::AlternativeTrigger (
      const Glib::ConstructParams& construct_params)
    : ShortcutTrigger (construct_params)
  {
  }

  AlternativeTrigger::AlternativeTrigger (GtkAlternativeTrigger* castitem)
    : ShortcutTrigger ((GtkShortcutTrigger*) (castitem))
  {
  }

  AlternativeTrigger::AlternativeTrigger (AlternativeTrigger&& src) noexcept
    : ShortcutTrigger (std::move (src))
  {
  }

  auto
  AlternativeTrigger::operator= (AlternativeTrigger&& src) noexcept -> AlternativeTrigger&
  {
    ShortcutTrigger::operator= (std::move (src));
    return *this;
  }

  AlternativeTrigger::~AlternativeTrigger () noexcept {}

  AlternativeTrigger::CppClassType
      AlternativeTrigger::alternativetrigger_class_;

  auto
  AlternativeTrigger::get_type () -> GType
  {
    return alternativetrigger_class_.init ().get_type ();
  }

  auto
  AlternativeTrigger::get_base_type () -> GType
  {
    return gtk_alternative_trigger_get_type ();
  }

  AlternativeTrigger::AlternativeTrigger (
      const Glib::RefPtr<const ShortcutTrigger>& first,
      const Glib::RefPtr<const ShortcutTrigger>& second)
    : Glib::ObjectBase (nullptr),
      ShortcutTrigger (Glib::ConstructParams (
          alternativetrigger_class_.init (),
          "first",
          const_cast<GtkShortcutTrigger*> (Glib::unwrap (first)),
          "second",
          const_cast<GtkShortcutTrigger*> (Glib::unwrap (second)),
          nullptr))
  {
  }

  auto
  AlternativeTrigger::create (const Glib::RefPtr<const ShortcutTrigger>& first,
                              const Glib::RefPtr<const ShortcutTrigger>& second) -> Glib::RefPtr<AlternativeTrigger>
  {
    return Glib::make_refptr_for_instance<AlternativeTrigger> (
        new AlternativeTrigger (first, second));
  }

  auto
  AlternativeTrigger::get_first () const -> Glib::RefPtr<const ShortcutTrigger>
  {
    auto retvalue = Glib::wrap (gtk_alternative_trigger_get_first (
        const_cast<GtkAlternativeTrigger*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  AlternativeTrigger::get_second () const -> Glib::RefPtr<const ShortcutTrigger>
  {
    auto retvalue = Glib::wrap (gtk_alternative_trigger_get_second (
        const_cast<GtkAlternativeTrigger*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<const ShortcutTrigger>>::value,
      "Type Glib::RefPtr<const ShortcutTrigger> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  AlternativeTrigger::property_first () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<const ShortcutTrigger>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<const ShortcutTrigger>> (
        this,
        "first");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<const ShortcutTrigger>>::value,
      "Type Glib::RefPtr<const ShortcutTrigger> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  AlternativeTrigger::property_second () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<const ShortcutTrigger>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<const ShortcutTrigger>> (
        this,
        "second");
  }

} // namespace Gtk
