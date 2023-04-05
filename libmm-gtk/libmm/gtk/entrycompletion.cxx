// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/entrycompletion.hxx>
  #include <libmm/gtk/entrycompletion_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/cellarea.hxx>
  #include <libmm/gtk/entry.hxx>
  #include <libmm/gtk/treeiter.hxx>

static auto
SignalProxy_Match_gtk_callback (GtkEntryCompletion* completion,
                                const char* key,
                                GtkTreeIter* iter,
                                gpointer user_data) -> gboolean
{
  auto the_slot = static_cast<gtk::EntryCompletion::SlotMatch*> (user_data);

  try
  {
    auto tree_model = gtk_entry_completion_get_model (completion);
    return (*the_slot) (glib::convert_const_gchar_ptr_to_ustring (key),
                        gtk::TreeModel::const_iterator (tree_model, iter));
  }
  catch (...)
  {
    glib::exception_handlers_invoke ();
  }

  return false;
}

static auto
SignalProxy_Match_gtk_callback_destroy (void* data) -> void
{
  delete static_cast<gtk::EntryCompletion::SlotMatch*> (data);
}

namespace gtk
{

  auto
  EntryCompletion::unset_model () -> void
  {
    gtk_entry_completion_set_model (gobj (), nullptr);
  }

  auto
  EntryCompletion::set_match_func (const SlotMatch& slot) -> void
  {
    auto slot_copy = new SlotMatch (slot);

    gtk_entry_completion_set_match_func (
        gobj (),
        &SignalProxy_Match_gtk_callback,
        slot_copy,
        &SignalProxy_Match_gtk_callback_destroy);
  }

} // namespace gtk

namespace
{

  static auto
  Widget_signal_match_selected_callback (GtkEntryCompletion* self,
                                         GtkTreeModel* c_model,
                                         GtkTreeIter* c_iter,
                                         void* data) -> gboolean
  {
    using namespace gtk;
    typedef sigc::slot<bool (const TreeModel::iterator&)> SlotType;

    if (glib::ObjectBase::_get_current_wrapper ((GObject*) self))
    {
      try
      {
        if (sigc::slot_base* const slot =
                glib::SignalProxyNormal::data_to_slot (data))
        {
          gtk::TreeModel::iterator cppIter (c_model, c_iter);

          return static_cast<int> ((*static_cast<SlotType*> (slot)) (cppIter));
        }
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    typedef gboolean RType;
    return RType ();
  }

  static auto
  Widget_signal_match_selected_notify_callback (GtkEntryCompletion* self,
                                                GtkTreeModel* c_model,
                                                GtkTreeIter* c_iter,
                                                void* data) -> gboolean
  {
    using namespace gtk;
    typedef sigc::slot<void (const TreeModel::iterator&)> SlotType;

    if (glib::ObjectBase::_get_current_wrapper ((GObject*) self))
    {
      try
      {
        if (sigc::slot_base* const slot =
                glib::SignalProxyNormal::data_to_slot (data))
        {
          gtk::TreeModel::iterator cppIter (c_model, c_iter);

          (*static_cast<SlotType*> (slot)) (cppIter);
        }
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    typedef gboolean RType;
    return RType ();
  }

  const glib::SignalProxyInfo EntryCompletion_signal_match_selected_info = {
      "match_selected",
      (GCallback) &Widget_signal_match_selected_callback,
      (GCallback) &Widget_signal_match_selected_notify_callback};

  static auto
  Widget_signal_cursor_on_match_callback (GtkEntryCompletion* self,
                                          GtkTreeModel* c_model,
                                          GtkTreeIter* c_iter,
                                          void* data) -> gboolean
  {
    using namespace gtk;
    typedef sigc::slot<bool (const TreeModel::iterator&)> SlotType;

    if (glib::ObjectBase::_get_current_wrapper ((GObject*) self))
    {
      try
      {
        if (sigc::slot_base* const slot =
                glib::SignalProxyNormal::data_to_slot (data))
        {
          gtk::TreeModel::iterator cppIter (c_model, c_iter);

          return static_cast<int> ((*static_cast<SlotType*> (slot)) (cppIter));
        }
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    typedef gboolean RType;
    return RType ();
  }

  static auto
  Widget_signal_cursor_on_match_notify_callback (GtkEntryCompletion* self,
                                                 GtkTreeModel* c_model,
                                                 GtkTreeIter* c_iter,
                                                 void* data) -> gboolean
  {
    using namespace gtk;
    typedef sigc::slot<void (const TreeModel::iterator&)> SlotType;

    if (glib::ObjectBase::_get_current_wrapper ((GObject*) self))
    {
      try
      {
        if (sigc::slot_base* const slot =
                glib::SignalProxyNormal::data_to_slot (data))
        {
          gtk::TreeModel::iterator cppIter (c_model, c_iter);

          (*static_cast<SlotType*> (slot)) (cppIter);
        }
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    typedef gboolean RType;
    return RType ();
  }

  const glib::SignalProxyInfo EntryCompletion_signal_cursor_on_match_info = {
      "cursor_on_match",
      (GCallback) &Widget_signal_cursor_on_match_callback,
      (GCallback) &Widget_signal_cursor_on_match_notify_callback};

} // namespace

namespace gtk
{

  auto
  EntryCompletion::signal_match_selected () -> glib::SignalProxy<bool (const TreeModel::iterator&)>
  {
    return glib::SignalProxy<bool (const TreeModel::iterator&)> (
        this,
        &EntryCompletion_signal_match_selected_info);
  }

  auto
  EntryCompletion::signal_cursor_on_match () -> glib::SignalProxy<bool (const TreeModel::iterator&)>
  {
    return glib::SignalProxy<bool (const TreeModel::iterator&)> (
        this,
        &EntryCompletion_signal_cursor_on_match_info);
  }

} // namespace gtk

namespace
{

  static auto
  EntryCompletion_signal_insert_prefix_callback (GtkEntryCompletion* self,
                                                 const gchar* p0,
                                                 void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (const glib::ustring&)>;

    auto obj = dynamic_cast<EntryCompletion*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  EntryCompletion_signal_insert_prefix_notify_callback (
      GtkEntryCompletion* self,
      const gchar* p0,
      void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<EntryCompletion*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo EntryCompletion_signal_insert_prefix_info =
      {"insert_prefix",
       (GCallback) &EntryCompletion_signal_insert_prefix_callback,
       (GCallback) &EntryCompletion_signal_insert_prefix_notify_callback};

  static const glib::SignalProxyInfo EntryCompletion_signal_no_matches_info = {
      "no_matches",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkEntryCompletion* object, bool take_copy) -> glib::RefPtr<gtk::EntryCompletion>
  {
    return glib::make_refptr_for_instance<gtk::EntryCompletion> (
        dynamic_cast<gtk::EntryCompletion*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  EntryCompletion_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EntryCompletion_Class::class_init_function;

      register_derived_type (gtk_entry_completion_get_type ());

      CellLayout::add_interface (get_type ());
      Buildable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  EntryCompletion_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EntryCompletion_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new EntryCompletion ((GtkEntryCompletion*) object);
  }

  auto
  EntryCompletion::gobj_copy () -> GtkEntryCompletion*
  {
    reference ();
    return gobj ();
  }

  EntryCompletion::EntryCompletion (
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  EntryCompletion::EntryCompletion (GtkEntryCompletion* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  EntryCompletion::EntryCompletion (EntryCompletion&& src) noexcept
    : glib::Object (std::move (src)),
      CellLayout (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  EntryCompletion::operator= (EntryCompletion&& src) noexcept -> EntryCompletion&
  {
    glib::Object::operator= (std::move (src));
    CellLayout::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  EntryCompletion::~EntryCompletion () noexcept {}

  EntryCompletion::CppClassType EntryCompletion::entrycompletion_class_;

  auto
  EntryCompletion::get_type () -> GType
  {
    return entrycompletion_class_.init ().get_type ();
  }

  auto
  EntryCompletion::get_base_type () -> GType
  {
    return gtk_entry_completion_get_type ();
  }

  EntryCompletion::EntryCompletion ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (entrycompletion_class_.init ()))
  {
  }

  auto
  EntryCompletion::create () -> glib::RefPtr<EntryCompletion>
  {
    return glib::make_refptr_for_instance<EntryCompletion> (
        new EntryCompletion ());
  }

  auto
  EntryCompletion::get_entry () -> Entry*
  {
    return glib::wrap ((GtkEntry*) (gtk_entry_completion_get_entry (gobj ())));
  }

  auto
  EntryCompletion::get_entry () const -> const Entry*
  {
    return glib::wrap ((GtkEntry*) (gtk_entry_completion_get_entry (
        const_cast<GtkEntryCompletion*> (gobj ()))));
  }

  auto
  EntryCompletion::set_model (const glib::RefPtr<TreeModel>& model) -> void
  {
    gtk_entry_completion_set_model (gobj (), glib::unwrap (model));
  }

  auto
  EntryCompletion::get_model () -> glib::RefPtr<TreeModel>
  {
    auto retvalue = glib::wrap (gtk_entry_completion_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  EntryCompletion::get_model () const -> glib::RefPtr<const TreeModel>
  {
    return const_cast<EntryCompletion*> (this)->get_model ();
  }

  auto
  EntryCompletion::set_minimum_key_length (int length) -> void
  {
    gtk_entry_completion_set_minimum_key_length (gobj (), length);
  }

  auto
  EntryCompletion::get_minimum_key_length () const -> int
  {
    return gtk_entry_completion_get_minimum_key_length (
        const_cast<GtkEntryCompletion*> (gobj ()));
  }

  auto
  EntryCompletion::compute_prefix (const glib::ustring& key) -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_entry_completion_compute_prefix (gobj (), key.c_str ()));
  }

  auto
  EntryCompletion::complete () -> void
  {
    gtk_entry_completion_complete (gobj ());
  }

  auto
  EntryCompletion::insert_prefix () -> void
  {
    gtk_entry_completion_insert_prefix (gobj ());
  }

  auto
  EntryCompletion::set_inline_completion (bool inline_completion) -> void
  {
    gtk_entry_completion_set_inline_completion (
        gobj (),
        static_cast<int> (inline_completion));
  }

  auto
  EntryCompletion::get_inline_completion () const -> bool
  {
    return gtk_entry_completion_get_inline_completion (
        const_cast<GtkEntryCompletion*> (gobj ()));
  }

  auto
  EntryCompletion::set_inline_selection (bool inline_selection) -> void
  {
    gtk_entry_completion_set_inline_selection (
        gobj (),
        static_cast<int> (inline_selection));
  }

  auto
  EntryCompletion::get_inline_selection () const -> bool
  {
    return gtk_entry_completion_get_inline_selection (
        const_cast<GtkEntryCompletion*> (gobj ()));
  }

  auto
  EntryCompletion::set_popup_completion (bool popup_completion) -> void
  {
    gtk_entry_completion_set_popup_completion (
        gobj (),
        static_cast<int> (popup_completion));
  }

  auto
  EntryCompletion::get_popup_completion () const -> bool
  {
    return gtk_entry_completion_get_popup_completion (
        const_cast<GtkEntryCompletion*> (gobj ()));
  }

  auto
  EntryCompletion::set_popup_set_width (bool popup_set_width) -> void
  {
    gtk_entry_completion_set_popup_set_width (
        gobj (),
        static_cast<int> (popup_set_width));
  }

  auto
  EntryCompletion::get_popup_set_width () const -> bool
  {
    return gtk_entry_completion_get_popup_set_width (
        const_cast<GtkEntryCompletion*> (gobj ()));
  }

  auto
  EntryCompletion::set_popup_single_match (bool popup_single_match) -> void
  {
    gtk_entry_completion_set_popup_single_match (
        gobj (),
        static_cast<int> (popup_single_match));
  }

  auto
  EntryCompletion::get_popup_single_match () const -> bool
  {
    return gtk_entry_completion_get_popup_single_match (
        const_cast<GtkEntryCompletion*> (gobj ()));
  }

  auto
  EntryCompletion::get_completion_prefix () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_entry_completion_get_completion_prefix (
            const_cast<GtkEntryCompletion*> (gobj ())));
  }

  auto
  EntryCompletion::set_text_column (const TreeModelColumnBase& column) -> void
  {
    gtk_entry_completion_set_text_column (gobj (), (column).index ());
  }

  auto
  EntryCompletion::set_text_column (int column) -> void
  {
    gtk_entry_completion_set_text_column (gobj (), column);
  }

  auto
  EntryCompletion::get_text_column () const -> int
  {
    return gtk_entry_completion_get_text_column (
        const_cast<GtkEntryCompletion*> (gobj ()));
  }

  auto
  EntryCompletion::signal_insert_prefix () -> glib::SignalProxy<bool (const glib::ustring&)>
  {
    return glib::SignalProxy<bool (const glib::ustring&)> (
        this,
        &EntryCompletion_signal_insert_prefix_info);
  }

  auto
  EntryCompletion::signal_no_matches () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &EntryCompletion_signal_no_matches_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gtk::TreeModel>>::value,
      "Type glib::RefPtr<gtk::TreeModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  EntryCompletion::property_model () -> glib::PropertyProxy<glib::RefPtr<gtk::TreeModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gtk::TreeModel>> (this, "model");
  }

  auto
  EntryCompletion::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::TreeModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::TreeModel>> (this,
                                                                       "model");
  }

  auto
  EntryCompletion::property_minimum_key_length () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "minimum-key-length");
  }

  auto
  EntryCompletion::property_minimum_key_length () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "minimum-key-length");
  }

  auto
  EntryCompletion::property_text_column () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "text-column");
  }

  auto
  EntryCompletion::property_text_column () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "text-column");
  }

  auto
  EntryCompletion::property_inline_completion () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "inline-completion");
  }

  auto
  EntryCompletion::property_inline_completion () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "inline-completion");
  }

  auto
  EntryCompletion::property_popup_completion () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "popup-completion");
  }

  auto
  EntryCompletion::property_popup_completion () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "popup-completion");
  }

  auto
  EntryCompletion::property_popup_set_width () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "popup-set-width");
  }

  auto
  EntryCompletion::property_popup_set_width () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "popup-set-width");
  }

  auto
  EntryCompletion::property_popup_single_match () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "popup-single-match");
  }

  auto
  EntryCompletion::property_popup_single_match () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "popup-single-match");
  }

  auto
  EntryCompletion::property_inline_selection () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "inline-selection");
  }

  auto
  EntryCompletion::property_inline_selection () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "inline-selection");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<CellArea>>::value,
      "Type glib::RefPtr<CellArea> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  EntryCompletion::property_cell_area () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<CellArea>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<CellArea>> (this,
                                                                 "cell-area");
  }

} // namespace gtk

#endif
