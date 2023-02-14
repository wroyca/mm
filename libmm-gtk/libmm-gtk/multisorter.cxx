

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/multisorter.hxx>
#include <libmm-gtk/multisorter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkMultiSorter* object, const bool take_copy) -> RefPtr<Gtk::MultiSorter>
  {
    return Glib::make_refptr_for_instance<Gtk::MultiSorter> (
        dynamic_cast<Gtk::MultiSorter*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  MultiSorter_Class::init () -> const Class&
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
  MultiSorter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MultiSorter ((GtkMultiSorter*) object);
  }

  auto
  MultiSorter::gobj_copy () -> GtkMultiSorter*
  {
    reference ();
    return gobj ();
  }

  MultiSorter::MultiSorter (const Glib::ConstructParams& construct_params)
    : Sorter (construct_params)
  {
  }

  MultiSorter::MultiSorter (GtkMultiSorter* castitem)
    : Sorter ((GtkSorter*) castitem)
  {
  }

  MultiSorter::MultiSorter (MultiSorter&& src) noexcept
    : Sorter (std::move (src)),
      ListModel (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  MultiSorter::operator= (MultiSorter&& src) noexcept -> MultiSorter&
  {
    Sorter::operator= (std::move (src));
    ListModel::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  MultiSorter::~MultiSorter () noexcept = default;

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
    : ObjectBase (nullptr),
      Sorter (Glib::ConstructParams (multisorter_class_.init ()))
  {
  }

  auto
  MultiSorter::create () -> Glib::RefPtr<MultiSorter>
  {
    return Glib::make_refptr_for_instance<MultiSorter> (new MultiSorter ());
  }

  auto
  MultiSorter::append (const Glib::RefPtr<Sorter>& sorter) -> void
  {
    gtk_multi_sorter_append (gobj (), unwrap_copy (sorter));
  }

  auto
  MultiSorter::remove (const guint position) -> void
  {
    gtk_multi_sorter_remove (gobj (), position);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MultiSorter::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return {this, "item-type"};
  }

  auto
  MultiSorter::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return {this, "n-items"};
  }

} // namespace Gtk
