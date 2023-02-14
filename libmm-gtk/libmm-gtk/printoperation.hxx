
#ifndef _GTKMM_PRINTOPERATION_H
#define _GTKMM_PRINTOPERATION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#include <libmm-gtk/pagesetup.hxx>
#include <libmm-gtk/printcontext.hxx>
#include <libmm-gtk/printoperationpreview.hxx>
#include <libmm-gtk/printsettings.hxx>
#include <libmm-gtk/window.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintOperation = struct _GtkPrintOperation;
using GtkPrintOperationClass = struct _GtkPrintOperationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API PrintOperation_Class;
}
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PrintStatus>
    : public Glib::Value_Enum<Gtk::PrintStatus>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class PrintError : public Glib::Error
  {
  public:
    enum Code
    {
      GENERAL,
      INTERNAL_ERROR,
      NOMEM,
      INVALID_FILE
    };

    GTKMM_API
    PrintError (Code error_code, const Glib::ustring& error_message);
    GTKMM_API explicit PrintError (GError* gobject);
    GTKMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GTKMM_API static void
    throw_func (GError* gobject);

    friend GTKMM_API void
    wrap_init ();

#endif
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PrintError::Code>
    : public Glib::Value_Enum<Gtk::PrintError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API PrintOperation : public Glib::Object,
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
    explicit PrintOperation (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<PrintOperation>;

    void
    set_default_page_setup (const Glib::RefPtr<PageSetup>& default_page_setup);

    auto
    get_default_page_setup () -> Glib::RefPtr<PageSetup>;

    auto
    get_default_page_setup () const -> Glib::RefPtr<const PageSetup>;

    void
    set_print_settings (const Glib::RefPtr<PrintSettings>& print_settings);

    auto
    get_print_settings () -> Glib::RefPtr<PrintSettings>;

    auto
    get_print_settings () const -> Glib::RefPtr<const PrintSettings>;

    void
    set_job_name (const Glib::ustring& job_name);

    void
    set_n_pages (int n_pages);

    void
    set_current_page (int current_page);

    void
    set_use_full_page (bool use_full_page = true);

    void
    set_unit (Unit unit);

    void
    set_export_filename (const std::string& filename);

    void
    set_track_print_status (bool track_status = true);

    void
    set_show_progress (bool show_progress = true);

    void
    set_allow_async (bool allow_async = true);

    void
    set_custom_tab_label (const Glib::ustring& label);

    auto
    run (Action action = Action::PRINT_DIALOG) -> Result;

    auto
    run (Action action, Window& parent) -> Result;

    auto
    get_status () const -> PrintStatus;

    auto
    get_status_string () const -> Glib::ustring;

    void
    cancel ();

    auto
    is_finished () const -> bool;

    void
    draw_page_finish ();

    void
    set_defer_drawing ();

    void
    set_support_selection (bool support_selection = true);

    auto
    get_support_selection () const -> bool;

    void
    set_has_selection (bool has_selection = true);

    auto
    get_has_selection () const -> bool;

    void
    set_embed_page_setup (bool embed = true);

    auto
    get_embed_page_setup () const -> bool;

    auto
    get_n_pages_to_print () const -> int;

    auto
    signal_done () -> Glib::SignalProxy<void (Result)>;

    auto
    signal_begin_print ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&)>;

    auto
    signal_paginate ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<PrintContext>&)>;

    auto
    signal_request_page_setup ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&,
                                   int,
                                   const Glib::RefPtr<PageSetup>&)>;

    auto
    signal_draw_page ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&, int)>;

    auto
    signal_end_print ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&)>;

    auto
    signal_status_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_create_custom_widget () -> Glib::SignalProxy<Widget*()>;

    auto
    signal_custom_widget_apply () -> Glib::SignalProxy<void (Widget*)>;

    auto
    signal_preview ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<PrintOperationPreview>&,
                                   const Glib::RefPtr<PrintContext>&,
                                   Window*)>;

    auto
    signal_update_custom_widget ()
        -> Glib::SignalProxy<void (Widget*,
                                   const Glib::RefPtr<PageSetup>&,
                                   const Glib::RefPtr<PrintSettings>&)>;

    auto
    property_default_page_setup ()
        -> Glib::PropertyProxy<Glib::RefPtr<PageSetup>>;

    auto
    property_default_page_setup () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PageSetup>>;

    auto
    property_print_settings ()
        -> Glib::PropertyProxy<Glib::RefPtr<PrintSettings>>;

    auto
    property_print_settings () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PrintSettings>>;

    auto
    property_job_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_job_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_n_pages () -> Glib::PropertyProxy<int>;

    auto
    property_n_pages () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_current_page () -> Glib::PropertyProxy<int>;

    auto
    property_current_page () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_use_full_page () -> Glib::PropertyProxy<bool>;

    auto
    property_use_full_page () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_track_print_status () -> Glib::PropertyProxy<bool>;

    auto
    property_track_print_status () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_unit () -> Glib::PropertyProxy<Unit>;

    auto
    property_unit () const -> Glib::PropertyProxy_ReadOnly<Unit>;

    auto
    property_show_progress () -> Glib::PropertyProxy<bool>;

    auto
    property_show_progress () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_async () -> Glib::PropertyProxy<bool>;

    auto
    property_allow_async () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_export_filename () -> Glib::PropertyProxy<std::string>;

    auto
    property_export_filename () const
        -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_status () const -> Glib::PropertyProxy_ReadOnly<PrintStatus>;

    auto
    property_status_string () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_custom_tab_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_custom_tab_label () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_support_selection () -> Glib::PropertyProxy<bool>;

    auto
    property_support_selection () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_selection () -> Glib::PropertyProxy<bool>;

    auto
    property_has_selection () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_embed_page_setup () -> Glib::PropertyProxy<bool>;

    auto
    property_embed_page_setup () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_n_pages_to_print () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
    virtual void
    on_done (Result result);

    virtual void
    on_begin_print (const Glib::RefPtr<PrintContext>& context);

    virtual auto
    on_paginate (const Glib::RefPtr<PrintContext>& context) -> bool;

    virtual void
    on_request_page_setup (const Glib::RefPtr<PrintContext>& context,
                           int page_no,
                           const Glib::RefPtr<PageSetup>& setup);

    virtual void
    on_draw_page (const Glib::RefPtr<PrintContext>& context, int page_nr);

    virtual void
    on_end_print (const Glib::RefPtr<PrintContext>& context);

    virtual void
    on_status_changed ();

    virtual auto
    on_create_custom_widget () -> Widget*;

    virtual void
    on_custom_widget_apply (Widget* widget);

    virtual auto
    on_preview (const Glib::RefPtr<PrintOperationPreview>& preview,
                const Glib::RefPtr<PrintContext>& context,
                Window* parent) -> bool;

    virtual void
    on_update_custom_widget (Widget* widget,
                             const Glib::RefPtr<PageSetup>& setup,
                             const Glib::RefPtr<PrintSettings>& settings);
  };

  GTKMM_API
  auto
  run_page_setup_dialog (
      Window& parent,
      const Glib::RefPtr<const PageSetup>& page_setup,
      const Glib::RefPtr<const PrintSettings>& print_settings) -> Glib::RefPtr<PageSetup>;

  GTKMM_API
  auto
  run_page_setup_dialog (
      Window& parent,
      const Glib::RefPtr<const PrintSettings>& print_settings) -> Glib::RefPtr<PageSetup>;

  typedef sigc::slot<void (const Glib::RefPtr<PageSetup>&)> SlotPrintSetupDone;

  GTKMM_API
  void
  run_page_setup_dialog_async (
      Window& parent,
      const Glib::RefPtr<const PageSetup>& page_setup,
      const Glib::RefPtr<const PrintSettings>& print_settings,
      const SlotPrintSetupDone& slot);

  GTKMM_API
  void
  run_page_setup_dialog_async (
      Window& parent,
      const Glib::RefPtr<const PrintSettings>& print_settings,
      const SlotPrintSetupDone& slot);

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PrintOperation::Result>
    : public Glib::Value_Enum<Gtk::PrintOperation::Result>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PrintOperation::Action>
    : public Glib::Value_Enum<Gtk::PrintOperation::Action>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkPrintOperation* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PrintOperation>;
} // namespace Glib

#endif
