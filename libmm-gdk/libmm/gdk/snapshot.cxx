// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/snapshot.hxx>
#include <libmm/gdk/snapshot_p.hxx>

#include <gdk/gdk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GdkSnapshot* object, bool take_copy) -> glib::RefPtr<gdk::Snapshot>
  {
    return glib::make_refptr_for_instance<gdk::Snapshot> (
        dynamic_cast<gdk::Snapshot*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Snapshot_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Snapshot_Class::class_init_function;

      register_derived_type (gdk_snapshot_get_type ());
    }

    return *this;
  }

  auto
  Snapshot_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Snapshot_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Snapshot ((GdkSnapshot*) object);
  }

  auto
  Snapshot::gobj_copy () -> GdkSnapshot*
  {
    reference ();
    return gobj ();
  }

  Snapshot::Snapshot (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Snapshot::Snapshot (GdkSnapshot* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Snapshot::Snapshot (Snapshot&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Snapshot::operator= (Snapshot&& src) noexcept -> Snapshot&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Snapshot::~Snapshot () noexcept {}

  Snapshot::CppClassType Snapshot::snapshot_class_;

  auto
  Snapshot::get_type () -> GType
  {
    return snapshot_class_.init ().get_type ();
  }

  auto
  Snapshot::get_base_type () -> GType
  {
    return gdk_snapshot_get_type ();
  }

} // namespace gdk
