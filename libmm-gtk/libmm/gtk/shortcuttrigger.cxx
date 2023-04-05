// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcuttrigger.hxx>
#include <libmm/gtk/shortcuttrigger_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkShortcutTrigger* object, bool take_copy) -> glib::RefPtr<gtk::ShortcutTrigger>
  {
    return glib::make_refptr_for_instance<gtk::ShortcutTrigger> (
        dynamic_cast<gtk::ShortcutTrigger*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ShortcutTrigger_Class::init () -> const glib::Class&
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
  ShortcutTrigger_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ShortcutTrigger::ShortcutTrigger (GtkShortcutTrigger* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  ShortcutTrigger::ShortcutTrigger (ShortcutTrigger&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  ShortcutTrigger::operator= (ShortcutTrigger&& src) noexcept -> ShortcutTrigger&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (shortcuttrigger_class_.init ()))
  {
  }

  auto
  ShortcutTrigger::parse_string (const glib::ustring& string) -> glib::RefPtr<ShortcutTrigger>
  {
    return glib::wrap (gtk_shortcut_trigger_parse_string (string.c_str ()));
  }

  auto
  ShortcutTrigger::to_string () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_shortcut_trigger_to_string (
            const_cast<GtkShortcutTrigger*> (gobj ())));
  }

  auto
  ShortcutTrigger::to_label (
      const glib::RefPtr<const gdk::Display>& display) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_shortcut_trigger_to_label (
            const_cast<GtkShortcutTrigger*> (gobj ()),
            const_cast<GdkDisplay*> (glib::unwrap (display))));
  }

  auto
  ShortcutTrigger::equal (
      const glib::RefPtr<const ShortcutTrigger>& trigger2) const -> bool
  {
    return gtk_shortcut_trigger_equal (
        const_cast<GtkShortcutTrigger*> (gobj ()),
        glib::unwrap (trigger2));
  }

  auto
  ShortcutTrigger::compare (
      const glib::RefPtr<const ShortcutTrigger>& trigger2) const -> int
  {
    return gtk_shortcut_trigger_compare (
        const_cast<GtkShortcutTrigger*> (gobj ()),
        glib::unwrap (trigger2));
  }

  auto
  ShortcutTrigger::trigger (const glib::RefPtr<const gdk::Event>& event,
                            bool enable_mnemonics) const -> gdk::KeyMatch
  {
    return static_cast<gdk::KeyMatch> (gtk_shortcut_trigger_trigger (
        const_cast<GtkShortcutTrigger*> (gobj ()),
        const_cast<GdkEvent*> (glib::unwrap (event)),
        static_cast<int> (enable_mnemonics)));
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkNeverTrigger* object, bool take_copy) -> glib::RefPtr<gtk::NeverTrigger>
  {
    return glib::make_refptr_for_instance<gtk::NeverTrigger> (
        dynamic_cast<gtk::NeverTrigger*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  NeverTrigger_Class::init () -> const glib::Class&
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
  NeverTrigger_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new NeverTrigger ((GtkNeverTrigger*) object);
  }

  auto
  NeverTrigger::gobj_copy () -> GtkNeverTrigger*
  {
    reference ();
    return gobj ();
  }

  NeverTrigger::NeverTrigger (const glib::ConstructParams& construct_params)
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
    : glib::ObjectBase (nullptr),
      ShortcutTrigger (glib::ConstructParams (nevertrigger_class_.init ()))
  {
  }

  auto
  NeverTrigger::get () -> glib::RefPtr<NeverTrigger>
  {
    auto retvalue = glib::wrap (GTK_NEVER_TRIGGER (gtk_never_trigger_get ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkKeyvalTrigger* object, bool take_copy) -> glib::RefPtr<gtk::KeyvalTrigger>
  {
    return glib::make_refptr_for_instance<gtk::KeyvalTrigger> (
        dynamic_cast<gtk::KeyvalTrigger*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  KeyvalTrigger_Class::init () -> const glib::Class&
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
  KeyvalTrigger_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new KeyvalTrigger ((GtkKeyvalTrigger*) object);
  }

  auto
  KeyvalTrigger::gobj_copy () -> GtkKeyvalTrigger*
  {
    reference ();
    return gobj ();
  }

  KeyvalTrigger::KeyvalTrigger (const glib::ConstructParams& construct_params)
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

  KeyvalTrigger::KeyvalTrigger (guint keyval, gdk::ModifierType modifiers)
    : glib::ObjectBase (nullptr),
      ShortcutTrigger (
          glib::ConstructParams (keyvaltrigger_class_.init (),
                                 "keyval",
                                 keyval,
                                 "modifiers",
                                 static_cast<GdkModifierType> (modifiers),
                                 nullptr))
  {
  }

  auto
  KeyvalTrigger::create (guint keyval, gdk::ModifierType modifiers) -> glib::RefPtr<KeyvalTrigger>
  {
    return glib::make_refptr_for_instance<KeyvalTrigger> (
        new KeyvalTrigger (keyval, modifiers));
  }

  auto
  KeyvalTrigger::get_keyval () const -> guint
  {
    return gtk_keyval_trigger_get_keyval (
        const_cast<GtkKeyvalTrigger*> (gobj ()));
  }

  auto
  KeyvalTrigger::get_modifiers () const -> gdk::ModifierType
  {
    return static_cast<gdk::ModifierType> (gtk_keyval_trigger_get_modifiers (
        const_cast<GtkKeyvalTrigger*> (gobj ())));
  }

  auto
  KeyvalTrigger::property_keyval () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "keyval");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::ModifierType>::value,
      "Type gdk::ModifierType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  KeyvalTrigger::property_modifiers () const -> glib::PropertyProxy_ReadOnly<gdk::ModifierType>
  {
    return glib::PropertyProxy_ReadOnly<gdk::ModifierType> (this, "modifiers");
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkMnemonicTrigger* object, bool take_copy) -> glib::RefPtr<gtk::MnemonicTrigger>
  {
    return glib::make_refptr_for_instance<gtk::MnemonicTrigger> (
        dynamic_cast<gtk::MnemonicTrigger*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  MnemonicTrigger_Class::init () -> const glib::Class&
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
  MnemonicTrigger_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
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
    : glib::ObjectBase (nullptr),
      ShortcutTrigger (glib::ConstructParams (mnemonictrigger_class_.init (),
                                              "keyval",
                                              keyval,
                                              nullptr))
  {
  }

  auto
  MnemonicTrigger::create (guint keyval) -> glib::RefPtr<MnemonicTrigger>
  {
    return glib::make_refptr_for_instance<MnemonicTrigger> (
        new MnemonicTrigger (keyval));
  }

  auto
  MnemonicTrigger::get_keyval () const -> guint
  {
    return gtk_mnemonic_trigger_get_keyval (
        const_cast<GtkMnemonicTrigger*> (gobj ()));
  }

  auto
  MnemonicTrigger::property_keyval () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "keyval");
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkAlternativeTrigger* object, bool take_copy) -> glib::RefPtr<gtk::AlternativeTrigger>
  {
    return glib::make_refptr_for_instance<gtk::AlternativeTrigger> (
        dynamic_cast<gtk::AlternativeTrigger*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  AlternativeTrigger_Class::init () -> const glib::Class&
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
  AlternativeTrigger_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
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
      const glib::RefPtr<const ShortcutTrigger>& first,
      const glib::RefPtr<const ShortcutTrigger>& second)
    : glib::ObjectBase (nullptr),
      ShortcutTrigger (glib::ConstructParams (
          alternativetrigger_class_.init (),
          "first",
          const_cast<GtkShortcutTrigger*> (glib::unwrap (first)),
          "second",
          const_cast<GtkShortcutTrigger*> (glib::unwrap (second)),
          nullptr))
  {
  }

  auto
  AlternativeTrigger::create (const glib::RefPtr<const ShortcutTrigger>& first,
                              const glib::RefPtr<const ShortcutTrigger>& second) -> glib::RefPtr<AlternativeTrigger>
  {
    return glib::make_refptr_for_instance<AlternativeTrigger> (
        new AlternativeTrigger (first, second));
  }

  auto
  AlternativeTrigger::get_first () const -> glib::RefPtr<const ShortcutTrigger>
  {
    auto retvalue = glib::wrap (gtk_alternative_trigger_get_first (
        const_cast<GtkAlternativeTrigger*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  AlternativeTrigger::get_second () const -> glib::RefPtr<const ShortcutTrigger>
  {
    auto retvalue = glib::wrap (gtk_alternative_trigger_get_second (
        const_cast<GtkAlternativeTrigger*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<const ShortcutTrigger>>::value,
      "Type glib::RefPtr<const ShortcutTrigger> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AlternativeTrigger::property_first () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<const ShortcutTrigger>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<const ShortcutTrigger>> (
        this,
        "first");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<const ShortcutTrigger>>::value,
      "Type glib::RefPtr<const ShortcutTrigger> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AlternativeTrigger::property_second () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<const ShortcutTrigger>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<const ShortcutTrigger>> (
        this,
        "second");
  }

} // namespace gtk
