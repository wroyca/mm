// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/constraintlayout.hxx>
#include <libmm/gtk/constraintlayout_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  ConstraintLayout::add_constraint (const glib::RefPtr<Constraint>& constraint) -> void
  {
    if (constraint)
      constraint->reference ();
    gtk_constraint_layout_add_constraint (gobj (), glib::unwrap (constraint));
  }

  auto
  ConstraintLayout::add_guide (const glib::RefPtr<ConstraintGuide>& guide) -> void
  {
    if (guide)
      guide->reference ();
    gtk_constraint_layout_add_guide (gobj (), glib::unwrap (guide));
  }

  auto
  ConstraintLayout::add_constraints_from_description (
      const std::vector<glib::ustring>& lines,
      int hspacing,
      int vspacing,
      const VFLmap& views) -> std::vector<glib::RefPtr<Constraint>>
  {
    GHashTable* hash_table_views = g_hash_table_new (g_str_hash, g_str_equal);
    for (const auto& it : views)
      g_hash_table_insert (hash_table_views,
                           const_cast<char*> (it.first.c_str ()),
                           it.second->gobj ());

    GError* gerror = nullptr;
    GList* constraints =
        gtk_constraint_layout_add_constraints_from_descriptionv (
            gobj (),
            glib::ArrayHandler<glib::ustring>::vector_to_array (lines).data (),
            lines.size (),
            hspacing,
            vspacing,
            hash_table_views,
            &gerror);

    g_hash_table_unref (hash_table_views);

    if (gerror)
    {
      g_list_free (constraints);
      ::glib::Error::throw_exception (gerror);
    }

    return glib::ListHandler<glib::RefPtr<Constraint>>::list_to_vector (
        constraints,
        glib::OWNERSHIP_SHALLOW);
  }

} // namespace gtk

namespace
{
}

gtk::ConstraintVflParserError::ConstraintVflParserError (
    gtk::ConstraintVflParserError::Code error_code,
    const glib::ustring& error_message)
  : glib::Error (GTK_CONSTRAINT_VFL_PARSER_ERROR, error_code, error_message)
{
}

gtk::ConstraintVflParserError::ConstraintVflParserError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gtk::ConstraintVflParserError::code () const
    -> gtk::ConstraintVflParserError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gtk::ConstraintVflParserError::throw_func (GError* gobject) -> void
{
  throw gtk::ConstraintVflParserError (gobject);
}

auto
glib::Value<gtk::ConstraintVflParserError::Code>::value_type () -> GType
{
  return gtk_constraint_vfl_parser_error_get_type ();
}

namespace glib
{

  auto
  wrap (GtkConstraintLayout* object, bool take_copy) -> glib::RefPtr<gtk::ConstraintLayout>
  {
    return glib::make_refptr_for_instance<gtk::ConstraintLayout> (
        dynamic_cast<gtk::ConstraintLayout*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ConstraintLayout_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ConstraintLayout_Class::class_init_function;

      gtype_ = gtk_constraint_layout_get_type ();
    }

    return *this;
  }

  auto
  ConstraintLayout_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ConstraintLayout_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ConstraintLayout ((GtkConstraintLayout*) object);
  }

  auto
  ConstraintLayout::gobj_copy () -> GtkConstraintLayout*
  {
    reference ();
    return gobj ();
  }

  ConstraintLayout::ConstraintLayout (
      const glib::ConstructParams& construct_params)
    : LayoutManager (construct_params)
  {
  }

  ConstraintLayout::ConstraintLayout (GtkConstraintLayout* castitem)
    : LayoutManager ((GtkLayoutManager*) (castitem))
  {
  }

  ConstraintLayout::ConstraintLayout (ConstraintLayout&& src) noexcept
    : LayoutManager (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  ConstraintLayout::operator= (ConstraintLayout&& src) noexcept -> ConstraintLayout&
  {
    LayoutManager::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  ConstraintLayout::~ConstraintLayout () noexcept {}

  ConstraintLayout::CppClassType ConstraintLayout::constraintlayout_class_;

  auto
  ConstraintLayout::get_type () -> GType
  {
    return constraintlayout_class_.init ().get_type ();
  }

  auto
  ConstraintLayout::get_base_type () -> GType
  {
    return gtk_constraint_layout_get_type ();
  }

  ConstraintLayout::ConstraintLayout ()
    : glib::ObjectBase (nullptr),
      LayoutManager (glib::ConstructParams (constraintlayout_class_.init ()))
  {
  }

  auto
  ConstraintLayout::create () -> glib::RefPtr<ConstraintLayout>
  {
    return glib::make_refptr_for_instance<ConstraintLayout> (
        new ConstraintLayout ());
  }

  auto
  ConstraintLayout::remove_constraint (
      const glib::RefPtr<Constraint>& constraint) -> void
  {
    gtk_constraint_layout_remove_constraint (gobj (),
                                             glib::unwrap (constraint));
  }

  auto
  ConstraintLayout::remove_all_constraints () -> void
  {
    gtk_constraint_layout_remove_all_constraints (gobj ());
  }

  auto
  ConstraintLayout::remove_guide (const glib::RefPtr<ConstraintGuide>& guide) -> void
  {
    gtk_constraint_layout_remove_guide (gobj (), glib::unwrap (guide));
  }

  auto
  ConstraintLayout::observe_constraints () -> glib::RefPtr<gio::ListModel>
  {
    return glib::wrap (gtk_constraint_layout_observe_constraints (gobj ()));
  }

  auto
  ConstraintLayout::observe_constraints () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<ConstraintLayout*> (this)->observe_constraints ();
  }

  auto
  ConstraintLayout::observe_guides () -> glib::RefPtr<gio::ListModel>
  {
    return glib::wrap (gtk_constraint_layout_observe_guides (gobj ()));
  }

  auto
  ConstraintLayout::observe_guides () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<ConstraintLayout*> (this)->observe_guides ();
  }

} // namespace gtk
