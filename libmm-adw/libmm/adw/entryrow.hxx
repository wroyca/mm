// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ENTRYROW_H
#define _LIBADWAITAMM_ENTRYROW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/preferencesrow.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT entry_row_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT entry_row : public adw::preferences_row,
                   public gtk::Editable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = entry_row;
    using CppClassType = entry_row_class;
    using BaseObjectType = AdwEntryRow;
    using BaseClassType = AdwEntryRowClass;
#endif

    entry_row (entry_row&& src) noexcept;
    auto
    operator= (entry_row&& src) noexcept -> entry_row&;

    entry_row (const entry_row&) = delete;
    auto
    operator= (const entry_row&) -> entry_row& = delete;

    ~entry_row () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class entry_row_class;
    static CppClassType entryrow_class_;

  protected:
    explicit entry_row (const glib::ConstructParams& construct_params);
    explicit entry_row (AdwEntryRow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwEntryRow*
    {
      return reinterpret_cast<AdwEntryRow*> (gobject_);
    }

    auto
    gobj () const -> const AdwEntryRow*
    {
      return reinterpret_cast<AdwEntryRow*> (gobject_);
    }

  private:
  public:
    entry_row ();

    auto
    add_prefix (gtk::Widget* widget) -> void;

    auto
    add_suffix (gtk::Widget* widget) -> void;

    auto
    get_activates_default () const -> bool;

    auto
    get_attributes () const -> pango::AttrList;

    auto
    get_enable_moji_completion () const -> bool;

    auto
    get_input_hints () const -> gtk::InputHints;

    auto
    get_input_purpose () const -> gtk::InputPurpose;

    auto
    get_show_apply_button () const -> bool;

    auto
    remove (gtk::Widget* widget) -> void;

    auto
    set_activates_default (bool activates) -> void;

    auto
    set_attributes (pango::AttrList& attributes) -> void;

    auto
    set_enable_emoji_completion (bool activates) -> void;

    auto
    set_input_hints (gtk::InputHints hints) -> void;

    auto
    set_input_purpose (gtk::InputPurpose purpose) -> void;

    auto
    set_show_apply_button (bool activates) -> void;

    auto
    property_activates_default () -> glib::PropertyProxy<bool>;

    auto
    property_activates_default () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_attributes () -> glib::PropertyProxy<pango::AttrList>;

    auto
    property_attributes () const
        -> glib::PropertyProxy_ReadOnly<pango::AttrList>;

    auto
    property_enable_emoji_completion () -> glib::PropertyProxy<bool>;

    auto
    property_enable_emoji_completion () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_input_hints () -> glib::PropertyProxy<gtk::InputHints>;

    auto
    property_input_hints () const
        -> glib::PropertyProxy_ReadOnly<gtk::InputHints>;

    auto
    property_input_purpose () -> glib::PropertyProxy<gtk::InputPurpose>;

    auto
    property_input_purpose () const
        -> glib::PropertyProxy_ReadOnly<gtk::InputPurpose>;

    auto
    property_show_apply_button () -> glib::PropertyProxy<bool>;

    auto
    property_show_apply_button () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_apply () -> glib::SignalProxy<void ()>;

    auto
    signal_entry_activated () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwEntryRow* object, bool take_copy = false) -> adw::entry_row*;
}

#endif
