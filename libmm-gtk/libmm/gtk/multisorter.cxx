// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/multisorter.hxx>
#include <libmm/gtk/multisorter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkMultiSorter* object, bool take_copy) -> glib::RefPtr<gtk::MultiSorter>
  {
    return glib::make_refptr_for_instance<gtk::MultiSorter> (
        dynamic_cast<gtk::MultiSorter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  MultiSorter_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MultiSorter_Class::class_init_function;

      gtype_ = gtk_multi_sorter_get_type ();
    }

    return *this;
  }

  auto
  MultiSorter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MultiSorter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MultiSorter ((GtkMultiSorter*) object);
  }

  auto
  MultiSorter::gobj_copy () -> GtkMultiSorter*
  {
    reference ();
    return gobj ();
  }

  MultiSorter::MultiSorter (const glib::ConstructParams& construct_params)
    : gtk::Sorter (construct_params)
  {
  }

  MultiSorter::MultiSorter (GtkMultiSorter* castitem)
    : gtk::Sorter ((GtkSorter*) (castitem))
  {
  }

  MultiSorter::MultiSorter (MultiSorter&& src) noexcept
    : gtk::Sorter (std::move (src)),
      gio::ListModel (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  MultiSorter::operator= (MultiSorter&& src) noexcept -> MultiSorter&
  {
    gtk::Sorter::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  MultiSorter::~MultiSorter () noexcept {}

  MultiSorter::CppClassType MultiSorter::multisorter_class_;

  auto
  MultiSorter::get_type () -> GType
  {
    return multisorter_class_.init ().get_type ();
  }

  auto
  MultiSorter::get_base_type () -> GType
  {
    return gtk_multi_sorter_get_type ();
  }

  MultiSorter::MultiSorter ()
    : glib::ObjectBase (nullptr),
      gtk::Sorter (glib::ConstructParams (multisorter_class_.init ()))
  {
  }

  auto
  MultiSorter::create () -> glib::RefPtr<MultiSorter>
  {
    return glib::make_refptr_for_instance<MultiSorter> (new MultiSorter ());
  }

  auto
  MultiSorter::append (const glib::RefPtr<Sorter>& sorter) -> void
  {
    gtk_multi_sorter_append (gobj (), glib::unwrap_copy (sorter));
  }

  auto
  MultiSorter::remove (guint position) -> void
  {
    gtk_multi_sorter_remove (gobj (), position);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MultiSorter::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  auto
  MultiSorter::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace gtk
