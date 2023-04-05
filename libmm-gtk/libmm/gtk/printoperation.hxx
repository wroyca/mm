// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTOPERATION_H
#define _GTKMM_PRINTOPERATION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#include <libmm/gtk/pagesetup.hxx>
#include <libmm/gtk/printcontext.hxx>
#include <libmm/gtk/printoperationpreview.hxx>
#include <libmm/gtk/printsettings.hxx>
#include <libmm/gtk/window.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintOperation = struct _GtkPrintOperation;
using GtkPrintOperationClass = struct _GtkPrintOperationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT PrintOperation_Class;
}
#endif

namespace gtk
{

  enum class PrintStatus
  {
    INITIAL,
    PREPARING,
    GENERATING_DATA,
    SENDING_DATA,
    PENDING,
    PENDING_ISSUE,
    PRINTING,
    FINISHED,
    FINISHED_ABORTED
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PrintStatus>
    : public glib::Value_Enum<gtk::PrintStatus>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class PrintError : public glib::Error
  {
  public:
    enum Code
    {
      GENERAL,
      INTERNAL_ERROR,
      NOMEM,
      INVALID_FILE
    };

    LIBMM_GTK_SYMEXPORT
    PrintError (Code error_code, const glib::ustring& error_message);
    LIBMM_GTK_SYMEXPORT explicit PrintError (GError* gobject);
    LIBMM_GTK_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GTK_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GTK_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PrintError::Code>
    : public glib::Value_Enum<gtk::PrintError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT PrintOperation : public glib::Object,
                                   public PrintOperationPreview
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PrintOperation;
    using CppClassType = PrintOperation_Class;
    using BaseObjectType = GtkPrintOperation;
    using BaseClassType = GtkPrintOperationClass;

    PrintOperation (const PrintOperation&) = delete;
    auto
    operator= (const PrintOperation&) -> PrintOperation& = delete;

  private:
    friend class PrintOperation_Class;
    static CppClassType printoperation_class_;

  protected:
    explicit PrintOperation (const glib::ConstructParams& construct_params);
    explicit PrintOperation (GtkPrintOperation* castitem);

#endif

  public:
    PrintOperation (PrintOperation&& src) noexcept;
    auto
    operator= (PrintOperation&& src) noexcept -> PrintOperation&;

    ~PrintOperation () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPrintOperation*
    {
      return reinterpret_cast<GtkPrintOperation*> (gobject_);
    }

    auto
    gobj () const -> const GtkPrintOperation*
    {
      return reinterpret_cast<GtkPrintOperation*> (gobject_);
    }

    auto
    gobj_copy () -> GtkPrintOperation*;

  private:
  protected:
    PrintOperation ();

  public:
    enum class Result
    {
      ERROR,
      APPLY,
      CANCEL,
      IN_PROGRESS
    };

    enum class Action
    {
      PRINT_DIALOG,
      PRINT,
      PREVIEW,
      EXPORT
    };

    static auto
    create () -> glib::RefPtr<PrintOperation>;

    auto
    set_default_page_setup (const glib::RefPtr<PageSetup>& default_page_setup)
        -> void;

    auto
    get_default_page_setup () -> glib::RefPtr<PageSetup>;

    auto
    get_default_page_setup () const -> glib::RefPtr<const PageSetup>;

    auto
    set_print_settings (const glib::RefPtr<PrintSettings>& print_settings)
        -> void;

    auto
    get_print_settings () -> glib::RefPtr<PrintSettings>;

    auto
    get_print_settings () const -> glib::RefPtr<const PrintSettings>;

    auto
    set_job_name (const glib::ustring& job_name) -> void;

    auto
    set_n_pages (int n_pages) -> void;

    auto
    set_current_page (int current_page) -> void;

    auto
    set_use_full_page (bool use_full_page = true) -> void;

    auto
    set_unit (Unit unit) -> void;

    auto
    set_export_filename (const std::string& filename) -> void;

    auto
    set_track_print_status (bool track_status = true) -> void;

    auto
    set_show_progress (bool show_progress = true) -> void;

    auto
    set_allow_async (bool allow_async = true) -> void;

    auto
    set_custom_tab_label (const glib::ustring& label) -> void;

    auto
    run (Action action = Action::PRINT_DIALOG) -> Result;

    auto
    run (Action action, Window& parent) -> Result;

    auto
    get_status () const -> PrintStatus;

    auto
    get_status_string () const -> glib::ustring;

    auto
    cancel () -> void;

    auto
    is_finished () const -> bool;

    auto
    draw_page_finish () -> void;

    auto
    set_defer_drawing () -> void;

    auto
    set_support_selection (bool support_selection = true) -> void;

    auto
    get_support_selection () const -> bool;

    auto
    set_has_selection (bool has_selection = true) -> void;

    auto
    get_has_selection () const -> bool;

    auto
    set_embed_page_setup (bool embed = true) -> void;

    auto
    get_embed_page_setup () const -> bool;

    auto
    get_n_pages_to_print () const -> int;

    auto
    signal_done () -> glib::SignalProxy<void (Result)>;

    auto
    signal_begin_print ()
        -> glib::SignalProxy<void (const glib::RefPtr<PrintContext>&)>;

    auto
    signal_paginate ()
        -> glib::SignalProxy<bool (const glib::RefPtr<PrintContext>&)>;

    auto
    signal_request_page_setup ()
        -> glib::SignalProxy<void (const glib::RefPtr<PrintContext>&,
                                   int,
                                   const glib::RefPtr<PageSetup>&)>;

    auto
    signal_draw_page ()
        -> glib::SignalProxy<void (const glib::RefPtr<PrintContext>&, int)>;

    auto
    signal_end_print ()
        -> glib::SignalProxy<void (const glib::RefPtr<PrintContext>&)>;

    auto
    signal_status_changed () -> glib::SignalProxy<void ()>;

    auto
    signal_create_custom_widget () -> glib::SignalProxy<Widget*()>;

    auto
    signal_custom_widget_apply () -> glib::SignalProxy<void (Widget*)>;

    auto
    signal_preview ()
        -> glib::SignalProxy<bool (const glib::RefPtr<PrintOperationPreview>&,
                                   const glib::RefPtr<PrintContext>&,
                                   Window*)>;

    auto
    signal_update_custom_widget ()
        -> glib::SignalProxy<void (Widget*,
                                   const glib::RefPtr<PageSetup>&,
                                   const glib::RefPtr<PrintSettings>&)>;

    auto
    property_default_page_setup ()
        -> glib::PropertyProxy<glib::RefPtr<PageSetup>>;

    auto
    property_default_page_setup () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<PageSetup>>;

    auto
    property_print_settings ()
        -> glib::PropertyProxy<glib::RefPtr<PrintSettings>>;

    auto
    property_print_settings () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<PrintSettings>>;

    auto
    property_job_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_job_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_n_pages () -> glib::PropertyProxy<int>;

    auto
    property_n_pages () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_current_page () -> glib::PropertyProxy<int>;

    auto
    property_current_page () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_use_full_page () -> glib::PropertyProxy<bool>;

    auto
    property_use_full_page () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_track_print_status () -> glib::PropertyProxy<bool>;

    auto
    property_track_print_status () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_unit () -> glib::PropertyProxy<Unit>;

    auto
    property_unit () const -> glib::PropertyProxy_ReadOnly<Unit>;

    auto
    property_show_progress () -> glib::PropertyProxy<bool>;

    auto
    property_show_progress () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_async () -> glib::PropertyProxy<bool>;

    auto
    property_allow_async () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_export_filename () -> glib::PropertyProxy<std::string>;

    auto
    property_export_filename () const
        -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_status () const -> glib::PropertyProxy_ReadOnly<PrintStatus>;

    auto
    property_status_string () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_custom_tab_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_custom_tab_label () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_support_selection () -> glib::PropertyProxy<bool>;

    auto
    property_support_selection () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_selection () -> glib::PropertyProxy<bool>;

    auto
    property_has_selection () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_embed_page_setup () -> glib::PropertyProxy<bool>;

    auto
    property_embed_page_setup () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_n_pages_to_print () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
    virtual auto
    on_done (Result result) -> void;

    virtual auto
    on_begin_print (const glib::RefPtr<PrintContext>& context) -> void;

    virtual auto
    on_paginate (const glib::RefPtr<PrintContext>& context) -> bool;

    virtual auto
    on_request_page_setup (const glib::RefPtr<PrintContext>& context,
                           int page_no,
                           const glib::RefPtr<PageSetup>& setup) -> void;

    virtual auto
    on_draw_page (const glib::RefPtr<PrintContext>& context, int page_nr)
        -> void;

    virtual auto
    on_end_print (const glib::RefPtr<PrintContext>& context) -> void;

    virtual auto
    on_status_changed () -> void;

    virtual auto
    on_create_custom_widget () -> Widget*;

    virtual auto
    on_custom_widget_apply (Widget* widget) -> void;

    virtual auto
    on_preview (const glib::RefPtr<PrintOperationPreview>& preview,
                const glib::RefPtr<PrintContext>& context,
                Window* parent) -> bool;

    virtual auto
    on_update_custom_widget (Widget* widget,
                             const glib::RefPtr<PageSetup>& setup,
                             const glib::RefPtr<PrintSettings>& settings)
        -> void;
  };

  LIBMM_GTK_SYMEXPORT auto
  run_page_setup_dialog (
      Window& parent,
      const glib::RefPtr<const PageSetup>& page_setup,
      const glib::RefPtr<const PrintSettings>& print_settings) -> glib::RefPtr<PageSetup>;

  LIBMM_GTK_SYMEXPORT auto
  run_page_setup_dialog (
      Window& parent,
      const glib::RefPtr<const PrintSettings>& print_settings) -> glib::RefPtr<PageSetup>;

  typedef sigc::slot<void (const glib::RefPtr<PageSetup>&)> SlotPrintSetupDone;

  LIBMM_GTK_SYMEXPORT auto
  run_page_setup_dialog_async (
      Window& parent,
      const glib::RefPtr<const PageSetup>& page_setup,
      const glib::RefPtr<const PrintSettings>& print_settings,
      const SlotPrintSetupDone& slot) -> void;

  LIBMM_GTK_SYMEXPORT auto
  run_page_setup_dialog_async (
      Window& parent,
      const glib::RefPtr<const PrintSettings>& print_settings,
      const SlotPrintSetupDone& slot) -> void;

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PrintOperation::Result>
    : public glib::Value_Enum<gtk::PrintOperation::Result>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PrintOperation::Action>
    : public glib::Value_Enum<gtk::PrintOperation::Action>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPrintOperation* object, bool take_copy = false) -> glib::RefPtr<gtk::PrintOperation>;
} // namespace glib

#endif
