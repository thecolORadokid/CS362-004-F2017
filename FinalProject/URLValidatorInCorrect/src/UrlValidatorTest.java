/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;
import java.util.ArrayList;




/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   //protocol://host.subdomain.topdomain/dir1/dir2/filename.ext
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   ArrayList<String> testurls = new ArrayList<String>();
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   
	   //everything else valid or empty, different schemes
	   testurls.add("http://www.google.com");
	   testurls.add("http:/www.google.com");
	   testurls.add("http:///www.google.com");
	   testurls.add("http:\\www.google.com");
	   testurls.add("https://www.google.com");
	   testurls.add("ftp://www.google.com");
	   testurls.add("123://www.google.com");
	   testurls.add("foo://www.google.com");
	   //everything else valid or empty, different sub-domain
	   testurls.add("http://123.google.com");
	   testurls.add("http://1.2.3.google.com");
	   testurls.add("http://!@#.google.com");
	   testurls.add("http://foo.google.com");
	   //everything else valid or empty, different domain
	   testurls.add("http://www.google.edu");
	   testurls.add("http://www.google.co.uk");
	   testurls.add("http://www.google.123");
	   testurls.add("http://www.google.bar");
	   testurls.add("http://www.aaaaaaaaaaaaaaa.com");
	   testurls.add("http://www. .com");
	   testurls.add("http://www.google. ");
	   testurls.add("http://192.128.1.1");
	   testurls.add("http://1.1.1.1");
	   testurls.add("http://11.11.11.11");
	   testurls.add("http://111.111.111.111");
	   testurls.add("http://1111.1111.1111.1111");
	   testurls.add("http://1.1.1.1.1");
	   //everything else valid or empty, different port
	   testurls.add("http://www.google.com:0");
	   testurls.add("http://www.google.com: ");
	   testurls.add("http://www.google.com:80");
	   testurls.add("http://www.google.com:423");
	   testurls.add("http://www.google.com:32767");
	   testurls.add("http://www.google.com:32766");
	   testurls.add("http://www.google.com:65535");
	   testurls.add("http://www.google.com:65536");
	   testurls.add("http://www.google.com:foo");
	   testurls.add("https://www.google.com:423");
	   testurls.add("https://www.google.com:80");
	   testurls.add("https://www.google.com:bar");
	   testurls.add("ftp://www.google.com:21");
	   testurls.add("ftp://www.google.com:80");
	   testurls.add("ftp://www.google.com:bar");
	 //everything else valid or empty, different path
	   testurls.add("http://www.google.com/foo");
	   testurls.add("http://www.google.com/foo/bar");
	   testurls.add("http://www.google.com/~foo");
	   testurls.add("http://www.google.com//foo");
	   testurls.add("http://www.google.com/foo/bar/123/foobar");
	   testurls.add("http://www.google.com/foo?bar");
	   testurls.add("http://www.google.com/foo$");
	   testurls.add("http://www.google.com/ /");
	   testurls.add("http://www.google.com\foo");
	   for(String url : testurls)
       {
       	System.out.println(urlVal.isValid(url) + ": " + url);
       }
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()
   {
	   for(int i = 0;i<10000;i++)
	   {
		   
	   }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
