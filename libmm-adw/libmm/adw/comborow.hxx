// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_COMBOROW_H
#define _LIBADWAITAMM_COMBOROW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/actionrow.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT combo_row_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT combo_row : public adw::action_row
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = combo_row;
    using CppClassType = combo_row_class;
    using BaseObjectType = AdwComboRow;
    using BaseClassType = AdwComboRowClass;
#endif

    combo_row (combo_row&& src) noexcept;
    auto
    operator= (combo_row&& src) noexcept -> combo_row&;

    combo_row (const combo_row&) = delete;
    auto
    operator= (const combo_row&) -> combo_row& = delete;

    ~combo_row () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class combo_row_class;
    static CppClassType comborow_class_;

  protected:
    explicit combo_row (const glib::ConstructParams& construct_params);
    explicit combo_row (AdwComboRow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwComboRow*
    {
      return reinterpret_cast<AdwComboRow*> (gobject_);
    }

    auto
    gobj () const -> const AdwComboRow*
    {
      return reinterpret_cast<AdwComboRow*> (gobject_);
    }

  private:
  public:
    combo_row ();

    auto
    get_expression () const -> glib::RefPtr<gtk::Expression<glib::ustring>>;

    auto
    get_factory () const -> glib::RefPtr<gtk::ListItemFactory>;

    auto
    get_list_factory () const -> glib::RefPtr<gtk::ListItemFactory>;

    auto
    get_model () const -> glib::RefPtr<gio::ListModel>;

    auto
    get_selected () const -> guint;

    auto
    get_selected_item () const -> glib::RefPtr<glib::ObjectBase>;

    auto
    get_use_subtitle () const -> bool;

    auto
    set_factory (const glib::RefPtr<gtk::ListItemFactory>& factory) -> void;

    auto
    set_list_factory (const glib::RefPtr<gtk::ListItemFactory>& factory)
        -> void;

    auto
    set_use_subtitle (bool use_subtitle) const -> void;

    auto
    set_selected (guint position) const -> void;

    auto
    set_expression (
        const glib::RefPtr<gtk::Expression<glib::ustring>>& expression) -> void;

    auto
    set_model (const glib::RefPtr<gio::ListModel>& model) -> void;

    auto
    property_expression ()
        -> glib::PropertyProxy<glib::RefPtr<gtk::Expression<glib::ustring>>>;

    auto
    property_expression () const -> glib::PropertyProxy_ReadOnly<
        glib::RefPtr<gtk::Expression<glib::ustring>>>;

    auto
    property_selected_item () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>;

    auto
    property_selected () -> glib::PropertyProxy<guint>;

    auto
    property_selected () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_factory ()
        -> glib::PropertyProxy<glib::RefPtr<gtk::ListItemFactory>>;

    auto
    property_factory () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::ListItemFactory>>;

    auto
    property_list_factory ()
        -> glib::PropertyProxy<glib::RefPtr<gtk::ListItemFactory>>;

    auto
    property_list_factory () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::ListItemFactory>>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

    auto
    property_use_subtitle () -> glib::PropertyProxy<bool>;

    auto
    property_use_subtitle () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwComboRow* object, bool take_copy = false) -> adw::combo_row*;
}

#endif
