// Copyright (c) 2015, Robert Escriva
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Replicant nor the names of its contributors may be
//       used to endorse or promote products derived from this software without
//       specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef replicant_failure_tracker_h_
#define replicant_failure_tracker_h_

// Replicant
#include "namespace.h"
#include "common/configuration.h"
#include "common/constants.h"
#include "common/ids.h"

BEGIN_REPLICANT_NAMESPACE

class failure_tracker
{
public:
	failure_tracker(configuration *config);
	~failure_tracker() throw ();

public:
	void set_server_id(server_id us);
	void assume_all_alive();
	void proof_of_life(server_id si);
	bool suspect_failed(server_id si, uint64_t timeout);

private:
	failure_tracker(const failure_tracker &);
	failure_tracker &operator = (const failure_tracker &);

private:
	configuration *m_config;
	server_id m_us;
	uint64_t m_last_seen[REPLICANT_MAX_REPLICAS];
};

END_REPLICANT_NAMESPACE

#endif // replicant_failure_tracker_h_
