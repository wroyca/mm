// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/emblem.hxx>
#include <libmm/gio/emblem_p.hxx>

#include <gio/gio.h>

using Origin = gio::Emblem::Origin;

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GEmblem* object, const bool take_copy) -> RefPtr<gio::Emblem>
  {
    return glib::make_refptr_for_instance<gio::Emblem> (
        dynamic_cast<gio::Emblem*> (wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  Emblem_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Emblem_Class::class_init_function;

      register_derived_type (g_emblem_get_type ());

      Icon::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Emblem_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Emblem_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Emblem ((GEmblem*) object);
  }

  auto
  Emblem::gobj_copy () -> GEmblem*
  {
    reference ();
    return gobj ();
  }

  Emblem::Emblem (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Emblem::Emblem (GEmblem* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Emblem::Emblem (Emblem&& src) noexcept
    : Object (std::move (src)),
      Icon (std::move (src))
  {
  }

  auto
  Emblem::operator= (Emblem&& src) noexcept -> Emblem&
  {
    Object::operator= (std::move (src));
    Icon::operator= (std::move (src));
    return *this;
  }

  Emblem::~Emblem () noexcept = default;

  Emblem::CppClassType Emblem::emblem_class_;

  auto
  Emblem::get_type () -> GType
  {
    return emblem_class_.init ().get_type ();
  }

  auto
  Emblem::get_base_type () -> GType
  {
    return g_emblem_get_type ();
  }

  Emblem::Emblem (const glib::RefPtr<Icon>& icon)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (emblem_class_.init (),
                                     "icon",
                                     glib::unwrap (icon),
                                     nullptr))
  {
  }

  Emblem::Emblem (const glib::RefPtr<Icon>& icon, const Origin origin)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (emblem_class_.init (),
                                     "icon",
                                     glib::unwrap (icon),
                                     "origin",
                                     origin,
                                     nullptr))
  {
  }

  auto
  Emblem::create (const glib::RefPtr<Icon>& icon) -> glib::RefPtr<Emblem>
  {
    return glib::make_refptr_for_instance<Emblem> (new Emblem (icon));
  }

  auto
  Emblem::create (const glib::RefPtr<Icon>& icon, const Origin origin) -> glib::RefPtr<Emblem>
  {
    return glib::make_refptr_for_instance<Emblem> (new Emblem (icon, origin));
  }

  auto
  Emblem::get_icon () -> glib::RefPtr<Icon>
  {
    return glib::wrap (g_emblem_get_icon (gobj ()));
  }

  auto
  Emblem::get_icon () const -> glib::RefPtr<const Icon>
  {
    return const_cast<Emblem*> (this)->get_icon ();
  }

  auto
  Emblem::get_origin () const -> Origin
  {
    return static_cast<Origin> (
        g_emblem_get_origin (const_cast<GEmblem*> (gobj ())));
  }

} // namespace gio
