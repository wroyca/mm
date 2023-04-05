// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/multifilter.hxx>
#include <libmm/gtk/multifilter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkMultiFilter* object, bool take_copy) -> glib::RefPtr<gtk::MultiFilter>
  {
    return glib::make_refptr_for_instance<gtk::MultiFilter> (
        dynamic_cast<gtk::MultiFilter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  MultiFilter_Class::init () -> const glib::Class&
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
  MultiFilter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MultiFilter ((GtkMultiFilter*) object);
  }

  auto
  MultiFilter::gobj_copy () -> GtkMultiFilter*
  {
    reference ();
    return gobj ();
  }

  MultiFilter::MultiFilter (const glib::ConstructParams& construct_params)
    : gtk::Filter (construct_params)
  {
  }

  MultiFilter::MultiFilter (GtkMultiFilter* castitem)
    : gtk::Filter ((GtkFilter*) (castitem))
  {
  }

  MultiFilter::MultiFilter (MultiFilter&& src) noexcept
    : gtk::Filter (std::move (src)),
      gio::ListModel (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  MultiFilter::operator= (MultiFilter&& src) noexcept -> MultiFilter&
  {
    gtk::Filter::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Filter (glib::ConstructParams (multifilter_class_.init ()))
  {
  }

  auto
  MultiFilter::append (const glib::RefPtr<Filter>& filter) -> void
  {
    gtk_multi_filter_append (gobj (), glib::unwrap_copy (filter));
  }

  auto
  MultiFilter::remove (guint position) -> void
  {
    gtk_multi_filter_remove (gobj (), position);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MultiFilter::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  auto
  MultiFilter::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkAnyFilter* object, bool take_copy) -> glib::RefPtr<gtk::AnyFilter>
  {
    return glib::make_refptr_for_instance<gtk::AnyFilter> (
        dynamic_cast<gtk::AnyFilter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  AnyFilter_Class::init () -> const glib::Class&
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
  AnyFilter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new AnyFilter ((GtkAnyFilter*) object);
  }

  auto
  AnyFilter::gobj_copy () -> GtkAnyFilter*
  {
    reference ();
    return gobj ();
  }

  AnyFilter::AnyFilter (const glib::ConstructParams& construct_params)
    : gtk::MultiFilter (construct_params)
  {
  }

  AnyFilter::AnyFilter (GtkAnyFilter* castitem)
    : gtk::MultiFilter ((GtkMultiFilter*) (castitem))
  {
  }

  AnyFilter::AnyFilter (AnyFilter&& src) noexcept
    : gtk::MultiFilter (std::move (src))
  {
  }

  auto
  AnyFilter::operator= (AnyFilter&& src) noexcept -> AnyFilter&
  {
    gtk::MultiFilter::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::MultiFilter (glib::ConstructParams (anyfilter_class_.init ()))
  {
  }

  auto
  AnyFilter::create () -> glib::RefPtr<AnyFilter>
  {
    return glib::make_refptr_for_instance<AnyFilter> (new AnyFilter ());
  }

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkEveryFilter* object, bool take_copy) -> glib::RefPtr<gtk::EveryFilter>
  {
    return glib::make_refptr_for_instance<gtk::EveryFilter> (
        dynamic_cast<gtk::EveryFilter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  EveryFilter_Class::init () -> const glib::Class&
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
  EveryFilter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new EveryFilter ((GtkEveryFilter*) object);
  }

  auto
  EveryFilter::gobj_copy () -> GtkEveryFilter*
  {
    reference ();
    return gobj ();
  }

  EveryFilter::EveryFilter (const glib::ConstructParams& construct_params)
    : gtk::MultiFilter (construct_params)
  {
  }

  EveryFilter::EveryFilter (GtkEveryFilter* castitem)
    : gtk::MultiFilter ((GtkMultiFilter*) (castitem))
  {
  }

  EveryFilter::EveryFilter (EveryFilter&& src) noexcept
    : gtk::MultiFilter (std::move (src))
  {
  }

  auto
  EveryFilter::operator= (EveryFilter&& src) noexcept -> EveryFilter&
  {
    gtk::MultiFilter::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::MultiFilter (glib::ConstructParams (everyfilter_class_.init ()))
  {
  }

  auto
  EveryFilter::create () -> glib::RefPtr<EveryFilter>
  {
    return glib::make_refptr_for_instance<EveryFilter> (new EveryFilter ());
  }

} // namespace gtk
