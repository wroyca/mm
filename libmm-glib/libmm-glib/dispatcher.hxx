// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_DISPATCHER_H
#define _GLIBMM_DISPATCHER_H

#include <libmm-glib/main.hxx>
#include <sigc++/sigc++.h>

namespace Glib
{

  class GLIBMM_API Dispatcher
  {
  public:
    Dispatcher ();

    Dispatcher (const Dispatcher&) = delete;
    auto
    operator= (const Dispatcher&) -> Dispatcher& = delete;

    explicit Dispatcher (const Glib::RefPtr<MainContext>& context);
    ~Dispatcher () noexcept;

    void
    emit ();
    void
    operator() ();

    auto
    connect (const sigc::slot<void ()>& slot) -> sigc::connection;

    auto
    connect (sigc::slot<void ()>&& slot) -> sigc::connection;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    struct Impl;
#endif

  private:
    Impl* impl_;
  };

} // namespace Glib

#endif
