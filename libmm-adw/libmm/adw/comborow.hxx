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
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT ComboRow_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT ComboRow : public Adw::ActionRow
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ComboRow CppObjectType;
    typedef ComboRow_Class CppClassType;
    typedef AdwComboRow BaseObjectType;
    typedef AdwComboRowClass BaseClassType;
#endif

    ComboRow (ComboRow&& src) noexcept;
    auto
    operator= (ComboRow&& src) noexcept -> ComboRow&;

    ComboRow (const ComboRow&) = delete;
    auto
    operator= (const ComboRow&) -> ComboRow& = delete;

    ~ComboRow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ComboRow_Class;
    static CppClassType comborow_class_;

  protected:
    explicit ComboRow (const Glib::ConstructParams& construct_params);
    explicit ComboRow (AdwComboRow* castitem);

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
    ComboRow ();

    auto
    get_expression () const -> Glib::RefPtr<Gtk::Expression<Glib::ustring>>;

    auto
    get_factory () const -> Glib::RefPtr<Gtk::ListItemFactory>;

    auto
    get_list_factory () const -> Glib::RefPtr<Gtk::ListItemFactory>;

    auto
    get_model () const -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_selected () const -> guint;

    auto
    get_selected_item () const -> Glib::RefPtr<Glib::ObjectBase>;

    auto
    get_use_subtitle () const -> bool;

    auto
    set_factory (const Glib::RefPtr<Gtk::ListItemFactory>& factory) -> void;

    auto
    set_list_factory (const Glib::RefPtr<Gtk::ListItemFactory>& factory)
        -> void;

    auto
    set_use_subtitle (bool use_subtitle) const -> void;

    auto
    set_selected (guint position) const -> void;

    auto
    set_expression (
        const Glib::RefPtr<Gtk::Expression<Glib::ustring>>& expression) -> void;

    auto
    set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void;

    auto
    property_expression ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gtk::Expression<Glib::ustring>>>;

    auto
    property_expression () const -> Glib::PropertyProxy_ReadOnly<
        Glib::RefPtr<Gtk::Expression<Glib::ustring>>>;

    auto
    property_selected_item () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>;

    auto
    property_selected () -> Glib::PropertyProxy<guint>;

    auto
    property_selected () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_factory ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gtk::ListItemFactory>>;

    auto
    property_factory () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::ListItemFactory>>;

    auto
    property_list_factory ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gtk::ListItemFactory>>;

    auto
    property_list_factory () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::ListItemFactory>>;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_use_subtitle () -> Glib::PropertyProxy<bool>;

    auto
    property_use_subtitle () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwComboRow* object, bool take_copy = false) -> Adw::ComboRow*;
}

#endif
