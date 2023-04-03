// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/sorter.hxx>
#include <libmm/gtk/sorter_p.hxx>

#include <gtk/gtk.h>

using Order = Gtk::Sorter::Order;
using Change = Gtk::Sorter::Change;

namespace
{

  static auto
  Sorter_signal_changed_callback (GtkSorter* self,
                                  GtkSorterChange p0,
                                  void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Change)>;

    auto obj = dynamic_cast<Sorter*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<Change> (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Sorter_signal_changed_info = {
      "changed",
      (GCallback) &Sorter_signal_changed_callback,
      (GCallback) &Sorter_signal_changed_callback};

} // namespace

auto
Glib::Value<Gtk::Sorter::Order>::value_type () -> GType
{
  return gtk_sorter_order_get_type ();
}

auto
Glib::Value<Gtk::Sorter::Change>::value_type () -> GType
{
  return gtk_sorter_change_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkSorter* object, bool take_copy) -> Glib::RefPtr<Gtk::Sorter>
  {
    return Glib::make_refptr_for_instance<Gtk::Sorter> (
        dynamic_cast<Gtk::Sorter*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Sorter_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Sorter_Class::class_init_function;

      register_derived_type (gtk_sorter_get_type ());
    }

    return *this;
  }

  auto
  Sorter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->compare = &compare_vfunc_callback;
    klass->get_order = &get_order_vfunc_callback;
  }

  auto
  Sorter_Class::compare_vfunc_callback (GtkSorter* self,
                                        gpointer item1,
                                        gpointer item2) -> GtkOrdering
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<GtkOrdering> (obj->compare_vfunc (item1, item2));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->compare)
      return (*base->compare) (self, item1, item2);

    using RType = GtkOrdering;
    return RType ();
  }

  auto
  Sorter_Class::get_order_vfunc_callback (GtkSorter* self) -> GtkSorterOrder
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<GtkSorterOrder> (obj->get_order_vfunc ());
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->get_order)
      return (*base->get_order) (self);

    using RType = GtkSorterOrder;
    return RType ();
  }

  auto
  Sorter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Sorter ((GtkSorter*) object);
  }

  auto
  Sorter::gobj_copy () -> GtkSorter*
  {
    reference ();
    return gobj ();
  }

  Sorter::Sorter (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Sorter::Sorter (GtkSorter* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Sorter::Sorter (Sorter&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Sorter::operator= (Sorter&& src) noexcept -> Sorter&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  Sorter::~Sorter () noexcept {}

  Sorter::CppClassType Sorter::sorter_class_;

  auto
  Sorter::get_type () -> GType
  {
    return sorter_class_.init ().get_type ();
  }

  auto
  Sorter::get_base_type () -> GType
  {
    return gtk_sorter_get_type ();
  }

  Sorter::Sorter ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (sorter_class_.init ()))
  {
  }

  auto
  Sorter::compare (gpointer item1, gpointer item2) -> Ordering
  {
    return static_cast<Ordering> (gtk_sorter_compare (gobj (), item1, item2));
  }

  auto
  Sorter::get_order () const -> Order
  {
    return static_cast<Order> (
        gtk_sorter_get_order (const_cast<GtkSorter*> (gobj ())));
  }

  auto
  Sorter::changed (Change change) -> void
  {
    gtk_sorter_changed (gobj (), static_cast<GtkSorterChange> (change));
  }

  auto
  Sorter::signal_changed () -> Glib::SignalProxy<void (Change)>
  {
    return Glib::SignalProxy<void (Change)> (this, &Sorter_signal_changed_info);
  }

  auto
  Gtk::Sorter::compare_vfunc (gpointer item1, gpointer item2) -> Ordering
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->compare)
    {
      Ordering retval (
          static_cast<Ordering> ((*base->compare) (gobj (), item1, item2)));
      return retval;
    }

    using RType = Ordering;
    return RType ();
  }

  auto
  Gtk::Sorter::get_order_vfunc () -> Order
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_order)
    {
      Order retval (static_cast<Order> ((*base->get_order) (gobj ())));
      return retval;
    }

    using RType = Order;
    return RType ();
  }

} // namespace Gtk