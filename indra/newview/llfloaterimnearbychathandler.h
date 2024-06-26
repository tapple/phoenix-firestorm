/** 
 * @file llfloaterimnearbychathandler.h
 * @brief nearby chat notify
 *
 * $LicenseInfo:firstyear=2004&license=viewerlgpl$
 * Second Life Viewer Source Code
 * Copyright (C) 2010, Linden Research, Inc.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License only.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * Linden Research, Inc., 945 Battery Street, San Francisco, CA  94111  USA
 * $/LicenseInfo$
 */

#ifndef LL_LLFLOATERIMNEARBYCHATHANDLER_H
#define LL_LLFLOATERIMNEARBYCHATHANDLER_H

#include "llnotificationhandler.h"

class LLEventPump;

//add LLFloaterIMNearbyChatHandler to LLNotificationsUI namespace
namespace LLNotificationsUI{

class LLFloaterIMNearbyChatHandler : public LLChatHandler
{
public:
	LLFloaterIMNearbyChatHandler();
	virtual ~LLFloaterIMNearbyChatHandler();


	virtual void processChat(const LLChat& chat_msg, const LLSD &args);

	// <FS:Ansariel> Add notification callback for new chat
	typedef boost::signals2::signal<void(const LLSD&)> new_chat_signal_t;
	boost::signals2::connection addNewChatCallback(const new_chat_signal_t::slot_type& cb) { return mNewChatSignal.connect(cb); }
	// </FS:Ansariel>

protected:
	virtual void initChannel();

	static std::unique_ptr<LLEventPump> sChatWatcher;

	// <FS:Ansariel> Add notification callback for new chat
	new_chat_signal_t mNewChatSignal;
};

}

#endif /* LL_LLFLOATERIMNEARBYCHATHANDLER_H */
