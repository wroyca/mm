// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/emblemedicon.hxx>
#include <libmm/gio/emblemedicon_p.hxx>

#include <gio/gio.h>

namespace gio
{

  EmblemedIcon::EmblemedIcon (const glib::RefPtr<Icon>& icon)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (emblemedicon_class_.init (),
                                     "icon",
                                     glib::unwrap (icon),
                                     nullptr))
  {
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GEmblemedIcon* object, const bool take_copy) -> RefPtr<gio::EmblemedIcon>
  {
    return glib::make_refptr_for_instance<gio::EmblemedIcon> (
        dynamic_cast<gio::EmblemedIcon*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
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
  EmblemedIcon_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new EmblemedIcon ((GEmblemedIcon*) object);
  }

  auto
  EmblemedIcon::gobj_copy () -> GEmblemedIcon*
  {
    reference ();
    return gobj ();
  }

  EmblemedIcon::EmblemedIcon (const glib::ConstructParams& construct_params)
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

  EmblemedIcon::EmblemedIcon (const glib::RefPtr<Icon>& icon,
                              const glib::RefPtr<Emblem>& emblem)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (emblemedicon_class_.init (),
                                     "icon",
                                     glib::unwrap (icon),
                                     "emblem",
                                     glib::unwrap (emblem),
                                     nullptr))
  {
  }

  auto
  EmblemedIcon::create (const glib::RefPtr<Icon>& icon,
                        const glib::RefPtr<Emblem>& emblem) -> glib::RefPtr<EmblemedIcon>
  {
    return glib::make_refptr_for_instance<EmblemedIcon> (
        new EmblemedIcon (icon, emblem));
  }

  auto
  EmblemedIcon::create (const glib::RefPtr<Icon>& icon) -> glib::RefPtr<EmblemedIcon>
  {
    return glib::make_refptr_for_instance<EmblemedIcon> (
        new EmblemedIcon (icon));
  }

  auto
  EmblemedIcon::get_icon () -> glib::RefPtr<Icon>
  {
    return glib::wrap (g_emblemed_icon_get_icon (gobj ()));
  }

  auto
  EmblemedIcon::get_icon () const -> glib::RefPtr<const Icon>
  {
    return const_cast<EmblemedIcon*> (this)->get_icon ();
  }

  auto
  EmblemedIcon::get_emblems () -> std::vector<glib::RefPtr<Emblem>>
  {
    return glib::ListHandler<glib::RefPtr<Emblem>>::list_to_vector (
        g_emblemed_icon_get_emblems (gobj ()),
        glib::OWNERSHIP_NONE);
  }

  auto
  EmblemedIcon::get_emblems () const -> std::vector<glib::RefPtr<const Emblem>>
  {
    return glib::ListHandler<glib::RefPtr<const Emblem>>::list_to_vector (
        g_emblemed_icon_get_emblems (const_cast<GEmblemedIcon*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  EmblemedIcon::add_emblem (const glib::RefPtr<Emblem>& emblem) -> void
  {
    g_emblemed_icon_add_emblem (gobj (), glib::unwrap (emblem));
  }

  auto
  EmblemedIcon::clear_emblems () -> void
  {
    g_emblemed_icon_clear_emblems (gobj ());
  }

} // namespace gio
