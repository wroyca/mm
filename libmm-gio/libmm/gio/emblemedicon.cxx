// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/emblemedicon.hxx>
#include <libmm/gio/emblemedicon_p.hxx>

#include <gio/gio.h>

namespace Gio
{

  EmblemedIcon::EmblemedIcon (const Glib::RefPtr<Icon>& icon)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (emblemedicon_class_.init (),
                                     "icon",
                                     Glib::unwrap (icon),
                                     nullptr))
  {
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GEmblemedIcon* object, const bool take_copy) -> RefPtr<Gio::EmblemedIcon>
  {
    return Glib::make_refptr_for_instance<Gio::EmblemedIcon> (
        dynamic_cast<Gio::EmblemedIcon*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  EmblemedIcon_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EmblemedIcon_Class::class_init_function;

      register_derived_type (g_emblemed_icon_get_type ());

      Icon::add_interface (get_type ());
    }

    return *this;
  }

  auto
  EmblemedIcon_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EmblemedIcon_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new EmblemedIcon ((GEmblemedIcon*) object);
  }

  auto
  EmblemedIcon::gobj_copy () -> GEmblemedIcon*
  {
    reference ();
    return gobj ();
  }

  EmblemedIcon::EmblemedIcon (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  EmblemedIcon::EmblemedIcon (GEmblemedIcon* castitem)
    : Object ((GObject*) castitem)
  {
  }

  EmblemedIcon::EmblemedIcon (EmblemedIcon&& src) noexcept
    : Object (std::move (src)),
      Icon (std::move (src))
  {
  }

  auto
  EmblemedIcon::operator= (EmblemedIcon&& src) noexcept -> EmblemedIcon&
  {
    Object::operator= (std::move (src));
    Icon::operator= (std::move (src));
    return *this;
  }

  EmblemedIcon::~EmblemedIcon () noexcept = default;

  EmblemedIcon::CppClassType EmblemedIcon::emblemedicon_class_;

  auto
  EmblemedIcon::get_type () -> GType
  {
    return emblemedicon_class_.init ().get_type ();
  }

  auto
  EmblemedIcon::get_base_type () -> GType
  {
    return g_emblemed_icon_get_type ();
  }

  EmblemedIcon::EmblemedIcon (const Glib::RefPtr<Icon>& icon,
                              const Glib::RefPtr<Emblem>& emblem)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (emblemedicon_class_.init (),
                                     "icon",
                                     Glib::unwrap (icon),
                                     "emblem",
                                     Glib::unwrap (emblem),
                                     nullptr))
  {
  }

  auto
  EmblemedIcon::create (const Glib::RefPtr<Icon>& icon,
                        const Glib::RefPtr<Emblem>& emblem) -> Glib::RefPtr<EmblemedIcon>
  {
    return Glib::make_refptr_for_instance<EmblemedIcon> (
        new EmblemedIcon (icon, emblem));
  }

  auto
  EmblemedIcon::create (const Glib::RefPtr<Icon>& icon) -> Glib::RefPtr<EmblemedIcon>
  {
    return Glib::make_refptr_for_instance<EmblemedIcon> (
        new EmblemedIcon (icon));
  }

  auto
  EmblemedIcon::get_icon () -> Glib::RefPtr<Icon>
  {
    return Glib::wrap (g_emblemed_icon_get_icon (gobj ()));
  }

  auto
  EmblemedIcon::get_icon () const -> Glib::RefPtr<const Icon>
  {
    return const_cast<EmblemedIcon*> (this)->get_icon ();
  }

  auto
  EmblemedIcon::get_emblems () -> std::vector<Glib::RefPtr<Emblem>>
  {
    return Glib::ListHandler<Glib::RefPtr<Emblem>>::list_to_vector (
        g_emblemed_icon_get_emblems (gobj ()),
        Glib::OWNERSHIP_NONE);
  }

  auto
  EmblemedIcon::get_emblems () const -> std::vector<Glib::RefPtr<const Emblem>>
  {
    return Glib::ListHandler<Glib::RefPtr<const Emblem>>::list_to_vector (
        g_emblemed_icon_get_emblems (const_cast<GEmblemedIcon*> (gobj ())),
        Glib::OWNERSHIP_NONE);
  }

  auto
  EmblemedIcon::add_emblem (const Glib::RefPtr<Emblem>& emblem) -> void
  {
    g_emblemed_icon_add_emblem (gobj (), Glib::unwrap (emblem));
  }

  auto
  EmblemedIcon::clear_emblems () -> void
  {
    g_emblemed_icon_clear_emblems (gobj ());
  }

} // namespace Gio
