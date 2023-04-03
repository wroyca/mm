// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/multifilter.hxx>
#include <libmm/gtk/multifilter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkMultiFilter* object, bool take_copy) -> Glib::RefPtr<Gtk::MultiFilter>
  {
    return Glib::make_refptr_for_instance<Gtk::MultiFilter> (
        dynamic_cast<Gtk::MultiFilter*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  MultiFilter_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MultiFilter_Class::class_init_function;

      gtype_ = gtk_multi_filter_get_type ();
    }

    return *this;
  }

  auto
  MultiFilter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MultiFilter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MultiFilter ((GtkMultiFilter*) object);
  }

  auto
  MultiFilter::gobj_copy () -> GtkMultiFilter*
  {
    reference ();
    return gobj ();
  }

  MultiFilter::MultiFilter (const Glib::ConstructParams& construct_params)
    : Gtk::Filter (construct_params)
  {
  }

  MultiFilter::MultiFilter (GtkMultiFilter* castitem)
    : Gtk::Filter ((GtkFilter*) (castitem))
  {
  }

  MultiFilter::MultiFilter (MultiFilter&& src) noexcept
    : Gtk::Filter (std::move (src)),
      Gio::ListModel (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  MultiFilter::operator= (MultiFilter&& src) noexcept -> MultiFilter&
  {
    Gtk::Filter::operator= (std::move (src));
    Gio::ListModel::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  MultiFilter::~MultiFilter () noexcept {}

  MultiFilter::CppClassType MultiFilter::multifilter_class_;

  auto
  MultiFilter::get_type () -> GType
  {
    return multifilter_class_.init ().get_type ();
  }

  auto
  MultiFilter::get_base_type () -> GType
  {
    return gtk_multi_filter_get_type ();
  }

  MultiFilter::MultiFilter ()
    : Glib::ObjectBase (nullptr),
      Gtk::Filter (Glib::ConstructParams (multifilter_class_.init ()))
  {
  }

  auto
  MultiFilter::append (const Glib::RefPtr<Filter>& filter) -> void
  {
    gtk_multi_filter_append (gobj (), Glib::unwrap_copy (filter));
  }

  auto
  MultiFilter::remove (guint position) -> void
  {
    gtk_multi_filter_remove (gobj (), position);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MultiFilter::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return Glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  auto
  MultiFilter::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return Glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace Gtk

namespace Glib
{

  auto
  wrap (GtkAnyFilter* object, bool take_copy) -> Glib::RefPtr<Gtk::AnyFilter>
  {
    return Glib::make_refptr_for_instance<Gtk::AnyFilter> (
        dynamic_cast<Gtk::AnyFilter*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  AnyFilter_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AnyFilter_Class::class_init_function;

      gtype_ = gtk_any_filter_get_type ();
    }

    return *this;
  }

  auto
  AnyFilter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AnyFilter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new AnyFilter ((GtkAnyFilter*) object);
  }

  auto
  AnyFilter::gobj_copy () -> GtkAnyFilter*
  {
    reference ();
    return gobj ();
  }

  AnyFilter::AnyFilter (const Glib::ConstructParams& construct_params)
    : Gtk::MultiFilter (construct_params)
  {
  }

  AnyFilter::AnyFilter (GtkAnyFilter* castitem)
    : Gtk::MultiFilter ((GtkMultiFilter*) (castitem))
  {
  }

  AnyFilter::AnyFilter (AnyFilter&& src) noexcept
    : Gtk::MultiFilter (std::move (src))
  {
  }

  auto
  AnyFilter::operator= (AnyFilter&& src) noexcept -> AnyFilter&
  {
    Gtk::MultiFilter::operator= (std::move (src));
    return *this;
  }

  AnyFilter::~AnyFilter () noexcept {}

  AnyFilter::CppClassType AnyFilter::anyfilter_class_;

  auto
  AnyFilter::get_type () -> GType
  {
    return anyfilter_class_.init ().get_type ();
  }

  auto
  AnyFilter::get_base_type () -> GType
  {
    return gtk_any_filter_get_type ();
  }

  AnyFilter::AnyFilter ()
    : Glib::ObjectBase (nullptr),
      Gtk::MultiFilter (Glib::ConstructParams (anyfilter_class_.init ()))
  {
  }

  auto
  AnyFilter::create () -> Glib::RefPtr<AnyFilter>
  {
    return Glib::make_refptr_for_instance<AnyFilter> (new AnyFilter ());
  }

} // namespace Gtk

namespace Glib
{

  auto
  wrap (GtkEveryFilter* object, bool take_copy) -> Glib::RefPtr<Gtk::EveryFilter>
  {
    return Glib::make_refptr_for_instance<Gtk::EveryFilter> (
        dynamic_cast<Gtk::EveryFilter*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  EveryFilter_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EveryFilter_Class::class_init_function;

      gtype_ = gtk_every_filter_get_type ();
    }

    return *this;
  }

  auto
  EveryFilter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EveryFilter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new EveryFilter ((GtkEveryFilter*) object);
  }

  auto
  EveryFilter::gobj_copy () -> GtkEveryFilter*
  {
    reference ();
    return gobj ();
  }

  EveryFilter::EveryFilter (const Glib::ConstructParams& construct_params)
    : Gtk::MultiFilter (construct_params)
  {
  }

  EveryFilter::EveryFilter (GtkEveryFilter* castitem)
    : Gtk::MultiFilter ((GtkMultiFilter*) (castitem))
  {
  }

  EveryFilter::EveryFilter (EveryFilter&& src) noexcept
    : Gtk::MultiFilter (std::move (src))
  {
  }

  auto
  EveryFilter::operator= (EveryFilter&& src) noexcept -> EveryFilter&
  {
    Gtk::MultiFilter::operator= (std::move (src));
    return *this;
  }

  EveryFilter::~EveryFilter () noexcept {}

  EveryFilter::CppClassType EveryFilter::everyfilter_class_;

  auto
  EveryFilter::get_type () -> GType
  {
    return everyfilter_class_.init ().get_type ();
  }

  auto
  EveryFilter::get_base_type () -> GType
  {
    return gtk_every_filter_get_type ();
  }

  EveryFilter::EveryFilter ()
    : Glib::ObjectBase (nullptr),
      Gtk::MultiFilter (Glib::ConstructParams (everyfilter_class_.init ()))
  {
  }

  auto
  EveryFilter::create () -> Glib::RefPtr<EveryFilter>
  {
    return Glib::make_refptr_for_instance<EveryFilter> (new EveryFilter ());
  }

} // namespace Gtk