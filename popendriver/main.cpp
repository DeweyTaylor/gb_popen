/*Copyright 2017 James Dewey Taylor
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <iostream>
#include "gb_popen.h"

using namespace std;

int main()
{
	FILE *fout;
	FILE *ferr;
	char buffer[512];
	char buffer2[512];
	int ret = gb_popen("../popentest/popentest", fout, ferr);
	if (ret != 0)
	{
		cout << "error" << ret << endl;
		return 0;
	}
	bool foutopen = true;
	bool ferropen = true;
	while (foutopen || ferropen)
	{
		if (foutopen && fgets(buffer, sizeof(buffer), fout) != NULL)
		{
			cout <<"DROUT: " << buffer << endl;
		}
		else
		{
			cout<<"DROUTCLOSED"<<endl;
			foutopen=false;
			gb_pclose(fout);
		}

		if (ferropen && fgets(buffer2, sizeof(buffer2), ferr) != NULL)
		{
			cout <<"DRERR: " << buffer2 << endl;
		}
		else
		{
			cout<<"DRERRCLOSED"<<endl;
			ferropen = false;
			gb_pclose(ferr);
		}
	}
	gb_pclose(fout);
	gb_pclose(ferr);
	return 0;
}
