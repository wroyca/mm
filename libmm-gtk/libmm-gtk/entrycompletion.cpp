


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/entrycompletion.hpp>
#include <mm/gtk/private/entrycompletion_p.hpp>


/* Copyright 2003 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <mm/gtk/treeiter.hpp>
#include <mm/gtk/cellarea.hpp>
#include <mm/gtk/entry.hpp>
#include <gtk/gtk.h>


static auto SignalProxy_Match_gtk_callback(GtkEntryCompletion* completion, const char* key, GtkTreeIter* iter, const gpointer user_data) -> gboolean
{
  const auto the_slot = static_cast<Gtk::EntryCompletion::SlotMatch*>(user_data);

  try
  {
    const auto tree_model = gtk_entry_completion_get_model(completion);
    return (*the_slot)(Glib::convert_const_gchar_ptr_to_ustring(key),
                         Gtk::TreeModel::const_iterator(tree_model, iter)
                         );
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return false; //An arbitary default, just to avoid the compiler warning.
}

static auto SignalProxy_Match_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::EntryCompletion::SlotMatch*>(data);
}


namespace Gtk
{

auto EntryCompletion::unset_model () -> void
{
  gtk_entry_completion_set_model(gobj(), nullptr);
}

auto EntryCompletion::set_match_func (const SlotMatch &slot) -> void
{
  // Create a copy of the slot.  A pointer to this will be passed
  // through the callback's data parameter.  It will be deleted
  // when SignalProxy_Match_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotMatch(slot);

  gtk_entry_completion_set_match_func(gobj(),
      &SignalProxy_Match_gtk_callback, slot_copy,
      &SignalProxy_Match_gtk_callback_destroy);
}

} //namespace Gtk

namespace //anonymous
{

auto Widget_signal_match_selected_callback(GtkEntryCompletion* self, GtkTreeModel* c_model, GtkTreeIter* c_iter, void* data) -> gboolean
{
  using namespace Gtk;
  typedef sigc::slot<bool(const TreeModel::iterator&)> SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    try
    {
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
      {
        //This conversion is the custom-written part:
        const TreeModel::iterator cppIter(c_model, c_iter);

        return (*static_cast<SlotType*>(slot))(cppIter);
      }
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  typedef gboolean RType;
  return RType();
}

auto Widget_signal_match_selected_notify_callback(GtkEntryCompletion* self, GtkTreeModel* c_model, GtkTreeIter* c_iter, void* data) -> gboolean
{
  using namespace Gtk;
  typedef sigc::slot<void(const TreeModel::iterator&)> SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    try
    {
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
      {
        //This conversion is the custom-written part:
        const TreeModel::iterator cppIter(c_model, c_iter);

        (*static_cast<SlotType*>(slot))(cppIter);
      }
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  typedef gboolean RType;
  return RType();
}

const Glib::SignalProxyInfo EntryCompletion_signal_match_selected_info =
{
  "match_selected",
  (GCallback) &Widget_signal_match_selected_callback,
  (GCallback) &Widget_signal_match_selected_notify_callback
};


auto Widget_signal_cursor_on_match_callback(GtkEntryCompletion* self, GtkTreeModel* c_model, GtkTreeIter* c_iter, void* data) -> gboolean
{
  using namespace Gtk;
  typedef sigc::slot<bool(const TreeModel::iterator&)> SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    try
    {
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
      {
        //This conversion is the custom-written part:
        const TreeModel::iterator cppIter(c_model, c_iter);

        return (*static_cast<SlotType*>(slot))(cppIter);
      }
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  typedef gboolean RType;
  return RType();
}

auto Widget_signal_cursor_on_match_notify_callback(GtkEntryCompletion* self, GtkTreeModel* c_model, GtkTreeIter* c_iter, void* data) -> gboolean
{
  using namespace Gtk;
  typedef sigc::slot<void(const TreeModel::iterator&)> SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    try
    {
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
      {
        //This conversion is the custom-written part:
        const TreeModel::iterator cppIter(c_model, c_iter);

        (*static_cast<SlotType*>(slot))(cppIter);
      }
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  typedef gboolean RType;
  return RType();
}

const Glib::SignalProxyInfo EntryCompletion_signal_cursor_on_match_info =
{
  "cursor_on_match",
  (GCallback) &Widget_signal_cursor_on_match_callback,
  (GCallback) &Widget_signal_cursor_on_match_notify_callback
};

} //anonymous namespace

namespace Gtk
{

//Hand-coded signal wrapping:

auto EntryCompletion::signal_match_selected() -> Glib::SignalProxy<bool(const TreeModel::iterator&)>
{
  return {this, &EntryCompletion_signal_match_selected_info};
}

auto EntryCompletion::signal_cursor_on_match() -> Glib::SignalProxy<bool(const TreeModel::iterator&)>
{
  return {this, &EntryCompletion_signal_cursor_on_match_info};
}


} // namespace Gtk

namespace
{


auto EntryCompletion_signal_insert_prefix_callback(GtkEntryCompletion* self, const gchar* p0,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(const Glib::ustring&)>;

  const auto obj = dynamic_cast<EntryCompletion*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
        );
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto EntryCompletion_signal_insert_prefix_notify_callback(GtkEntryCompletion* self, const gchar* p0, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&)>;

  const auto obj = dynamic_cast<EntryCompletion*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo EntryCompletion_signal_insert_prefix_info =
{
  "insert_prefix",
  (GCallback) &EntryCompletion_signal_insert_prefix_callback,
  (GCallback) &EntryCompletion_signal_insert_prefix_notify_callback
};


const Glib::SignalProxyInfo EntryCompletion_signal_no_matches_info =
{
  "no_matches",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkEntryCompletion* object, const bool take_copy) -> RefPtr<Gtk::EntryCompletion>
{
  return Glib::make_refptr_for_instance<Gtk::EntryCompletion>( dynamic_cast<Gtk::EntryCompletion*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto EntryCompletion_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EntryCompletion_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_entry_completion_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  CellLayout::add_interface(get_type());
  Buildable::add_interface(get_type());

  }

  return *this;
}


auto EntryCompletion_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto EntryCompletion_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new EntryCompletion((GtkEntryCompletion*)object);
}


/* The implementation: */

auto EntryCompletion::gobj_copy() -> GtkEntryCompletion*
{
  reference();
  return gobj();
}

EntryCompletion::EntryCompletion(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

EntryCompletion::EntryCompletion(GtkEntryCompletion* castitem)
: Object((GObject*)castitem)
{}


EntryCompletion::EntryCompletion(EntryCompletion&& src) noexcept
: Object(std::move(src))
  , CellLayout(std::move(src))
  , Buildable(std::move(src))
{}

auto EntryCompletion::operator=(EntryCompletion&& src) noexcept -> EntryCompletion&
{
  Object::operator=(std::move(src));
  CellLayout::operator=(std::move(src));
  Buildable::operator=(std::move(src));
  return *this;
}


EntryCompletion::~EntryCompletion() noexcept = default;

EntryCompletion::CppClassType EntryCompletion::entrycompletion_class_; // initialize static member

auto EntryCompletion::get_type() -> GType
{
  return entrycompletion_class_.init().get_type();
}


auto EntryCompletion::get_base_type() -> GType
{
  return gtk_entry_completion_get_type();
}


EntryCompletion::EntryCompletion()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(entrycompletion_class_.init()))
{


}

auto EntryCompletion::create() -> Glib::RefPtr<EntryCompletion>
{
  return Glib::make_refptr_for_instance<EntryCompletion>( new EntryCompletion() );
}

auto EntryCompletion::get_entry() -> Entry*
{
  return Glib::wrap((GtkEntry*)gtk_entry_completion_get_entry(gobj()));
}

auto EntryCompletion::get_entry() const -> const Entry*
{
  return Glib::wrap((GtkEntry*)gtk_entry_completion_get_entry(const_cast<GtkEntryCompletion*>(gobj())));
}

auto EntryCompletion::set_model (const Glib::RefPtr <TreeModel> &model) -> void
{
  gtk_entry_completion_set_model(gobj(), Glib::unwrap(model));
}

auto EntryCompletion::get_model() -> Glib::RefPtr<TreeModel>
{
  auto retvalue = Glib::wrap(gtk_entry_completion_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto EntryCompletion::get_model() const -> Glib::RefPtr<const TreeModel>
{
  return const_cast<EntryCompletion*>(this)->get_model();
}

auto EntryCompletion::set_minimum_key_length (
  const int length) -> void
{
  gtk_entry_completion_set_minimum_key_length(gobj(), length);
}

auto EntryCompletion::get_minimum_key_length() const -> int
{
  return gtk_entry_completion_get_minimum_key_length(const_cast<GtkEntryCompletion*>(gobj()));
}

auto EntryCompletion::compute_prefix(const Glib::ustring& key) -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_entry_completion_compute_prefix(gobj(), key.c_str()));
}

auto EntryCompletion::complete () -> void
{
  gtk_entry_completion_complete(gobj());
}

auto EntryCompletion::insert_prefix () -> void
{
  gtk_entry_completion_insert_prefix(gobj());
}

auto EntryCompletion::set_inline_completion (
  const bool inline_completion) -> void
{
  gtk_entry_completion_set_inline_completion(gobj(), inline_completion);
}

auto EntryCompletion::get_inline_completion() const -> bool
{
  return gtk_entry_completion_get_inline_completion(const_cast<GtkEntryCompletion*>(gobj()));
}

auto EntryCompletion::set_inline_selection (
  const bool inline_selection) -> void
{
  gtk_entry_completion_set_inline_selection(gobj(), inline_selection);
}

auto EntryCompletion::get_inline_selection() const -> bool
{
  return gtk_entry_completion_get_inline_selection(const_cast<GtkEntryCompletion*>(gobj()));
}

auto EntryCompletion::set_popup_completion (
  const bool popup_completion) -> void
{
  gtk_entry_completion_set_popup_completion(gobj(), popup_completion);
}

auto EntryCompletion::get_popup_completion() const -> bool
{
  return gtk_entry_completion_get_popup_completion(const_cast<GtkEntryCompletion*>(gobj()));
}

auto EntryCompletion::set_popup_set_width (
  const bool popup_set_width) -> void
{
  gtk_entry_completion_set_popup_set_width(gobj(), popup_set_width);
}

auto EntryCompletion::get_popup_set_width() const -> bool
{
  return gtk_entry_completion_get_popup_set_width(const_cast<GtkEntryCompletion*>(gobj()));
}

auto EntryCompletion::set_popup_single_match (
  const bool popup_single_match) -> void
{
  gtk_entry_completion_set_popup_single_match(gobj(), popup_single_match);
}

auto EntryCompletion::get_popup_single_match() const -> bool
{
  return gtk_entry_completion_get_popup_single_match(const_cast<GtkEntryCompletion*>(gobj()));
}

auto EntryCompletion::get_completion_prefix() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_entry_completion_get_completion_prefix(const_cast<GtkEntryCompletion*>(gobj())));
}

auto EntryCompletion::set_text_column (const TreeModelColumnBase &column) -> void
{
  gtk_entry_completion_set_text_column(gobj(), column.index());
}

auto EntryCompletion::set_text_column (
  const int column) -> void
{
  gtk_entry_completion_set_text_column(gobj(), column);
}

auto EntryCompletion::get_text_column() const -> int
{
  return gtk_entry_completion_get_text_column(const_cast<GtkEntryCompletion*>(gobj()));
}


auto EntryCompletion::signal_insert_prefix() -> Glib::SignalProxy<bool(const Glib::ustring&)>
{
  return {this, &EntryCompletion_signal_insert_prefix_info};
}


auto EntryCompletion::signal_no_matches() -> Glib::SignalProxy<void()>
{
  return {this, &EntryCompletion_signal_no_matches_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<TreeModel>>::value,
  "Type Glib::RefPtr<Gtk::TreeModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto EntryCompletion::property_model() -> Glib::PropertyProxy< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}

auto EntryCompletion::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}

auto EntryCompletion::property_minimum_key_length() -> Glib::PropertyProxy< int >
{
  return {this, "minimum-key-length"};
}

auto EntryCompletion::property_minimum_key_length() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "minimum-key-length"};
}

auto EntryCompletion::property_text_column() -> Glib::PropertyProxy< int >
{
  return {this, "text-column"};
}

auto EntryCompletion::property_text_column() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "text-column"};
}

auto EntryCompletion::property_inline_completion() -> Glib::PropertyProxy< bool >
{
  return {this, "inline-completion"};
}

auto EntryCompletion::property_inline_completion() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "inline-completion"};
}

auto EntryCompletion::property_popup_completion() -> Glib::PropertyProxy< bool >
{
  return {this, "popup-completion"};
}

auto EntryCompletion::property_popup_completion() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "popup-completion"};
}

auto EntryCompletion::property_popup_set_width() -> Glib::PropertyProxy< bool >
{
  return {this, "popup-set-width"};
}

auto EntryCompletion::property_popup_set_width() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "popup-set-width"};
}

auto EntryCompletion::property_popup_single_match() -> Glib::PropertyProxy< bool >
{
  return {this, "popup-single-match"};
}

auto EntryCompletion::property_popup_single_match() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "popup-single-match"};
}

auto EntryCompletion::property_inline_selection() -> Glib::PropertyProxy< bool >
{
  return {this, "inline-selection"};
}

auto EntryCompletion::property_inline_selection() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "inline-selection"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<CellArea>>::value,
  "Type Glib::RefPtr<CellArea> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto EntryCompletion::property_cell_area() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >
{
  return {this, "cell-area"};
}


} // namespace Gtk


