<?xml version="1.0" encoding="UTF-8"?>
<!--

 Copyright 2004-2005 The Apache Software Foundation.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
      http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

-->
<jsp:root             version="2.0"
                      xmlns:c="http://java.sun.com/jsp/jstl/core"
                      xmlns:f="http://java.sun.com/jsf/core"
                      xmlns:h="http://java.sun.com/jsf/html"
                    xmlns:jsp="http://java.sun.com/JSP/Page"
                      xmlns:s="http://struts.apache.org/shale/core">

  <jsp:directive.page
                  contentType="text/xml;charset=UTF-8"/>

  <items>
    <c:forEach            var="category"
                        items="${lookup$listCategories.supportedCategories}">
      <item>
        <label><c:out value="${category.label}"/></label>
        <value><c:out value="${category.value}"/></value>
      </item>
    </c:forEach>
  </items>

</jsp:root>