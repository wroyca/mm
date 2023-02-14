

#include <exception>
#include <glib.h>
#include <libmm-glib/error.hxx>
#include <libmm-glib/exceptionhandler.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <list>

namespace
{

  using HandlerList = std::list<sigc::slot<void ()>>;

  thread_local HandlerList* thread_specific_handler_list = nullptr;

  auto
  glibmm_exception_warning (const GError* error) -> void
  {
    g_assert (error != nullptr);

    g_critical ("\n"
                "unhandled exception (type Glib::Error) in signal handler:\n"
                "domain: %s\n"
                "code  : %d\n"
                "what  : %s\n",
                g_quark_to_string (error->domain),
                error->code,
                error->message ? error->message : "(null)");
  }

  auto
  glibmm_unexpected_exception () -> void
  {
    try
    {
      throw;
    }
    catch (const Glib::Error& error)
    {
      glibmm_exception_warning (error.gobj ());

      return;
    }
    catch (const std::exception& except)
    {
      g_error ("\n"
               "unhandled exception (type std::exception) in signal handler:\n"
               "what: %s\n",
               except.what ());
    }
    catch (...)
    {
      g_error ("\nunhandled exception (type unknown) in signal handler\n");
    }
  }

} // namespace

namespace Glib
{

  auto
  add_exception_handler (const sigc::slot<void ()>& slot) -> sigc::connection
  {
    HandlerList* handler_list = thread_specific_handler_list;

    if (!handler_list)
    {
      handler_list = new HandlerList ();
      thread_specific_handler_list = handler_list;
    }

    handler_list->emplace_back (slot);
    auto& added_slot = handler_list->back ();
    return sigc::connection (added_slot);
  }

  auto
  exception_handlers_invoke () noexcept -> void
  {
    if (HandlerList* const handler_list = thread_specific_handler_list)
    {
      HandlerList::iterator pslot = handler_list->begin ();

      while (pslot != handler_list->end ())
      {
        if (pslot->empty ())
        {
          pslot = handler_list->erase (pslot);
          continue;
        }

        try
        {
          (*pslot) ();
        }
        catch (...)
        {
          ++pslot;
          continue;
        }

        return;
      }
    }

    glibmm_unexpected_exception ();
  }

} // namespace Glib
