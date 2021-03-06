// Copyright (c) 2011 emo-framework project
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// * Neither the name of the project nor the names of its contributors may be
//   used to endorse or promote products derived from this software without
//   specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
#import "Foundation/Foundation.h"
#import "sqlite3.h"

@interface CipherHolder : NSObject { 
    NSString *_plainText;
    NSString *_cipher;
};

@property (readwrite) NSString *plainText;
@property (readwrite) NSString *cipher;

- (BOOL)hasCipher;
- (BOOL)compareWithCipher:(NSString *)cipher;
- (BOOL)compareWithHolder:(CipherHolder *)holder;
@end

@interface EmoDatabase : NSObject {
	sqlite3* db;
	BOOL isOpen;
	NSInteger lastError;
	NSString* lastErrorMessage;
}
@property (readwrite) NSInteger lastError;
@property (readwrite, copy) NSString* lastErrorMessage;

-(BOOL)open:(NSString*) name;
-(BOOL)open:(NSString*) name force:(BOOL)force;
-(BOOL)openOrCreate:(NSString*)name mode:(NSInteger)mode;
-(BOOL)close;
-(BOOL)deleteDatabase:(NSString*)name;
-(BOOL)openOrCreatePreference;
-(BOOL)openPreference;
-(NSString*)getPreference:(NSString*)key;
-(BOOL)setPreference:(NSString*) key value:(NSString*)value;
-(NSArray*)getPreferenceKeys;
-(BOOL)deletePreference:(NSString*)key;
-(NSInteger)getLastError;
-(NSString*)getLastErrorMessage;
-(NSString*)getPath:(NSString*)name;
@end
