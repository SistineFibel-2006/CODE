# Web 前端与后端基础全能速查表 (开卷考试专用)

## 目录索引

1.  **HTML 基础**：标签、表单、表格 (网页的骨架)
2.  **CSS 基础**：选择器、盒子模型、布局 (网页的样式)
3.  **HTML DOM**：原生 JS 操作页面元素 (动态交互)
4.  **jQuery**：简化的 JS 库 (更少代码做更多事)
5.  **JSP 基础**：Java 服务器页面 (后端逻辑与数据)

---

## 第一部分：HTML 基础 (网页骨架)

HTML 是网页的结构。考试常考：标签的作用、表单的写法、表格的合并。

### 1. HTML 基本结构模板
```html
<!DOCTYPE html> <html>
<head>
    <meta charset="utf-8"> <title>网页标题</title>
</head>
<body>
    <h1>这是一级标题</h1>
    <p>这是一个段落。</p>
</body>
</html>
```

### 2. 常用标签速查

| **标签**        | **描述**   | **示例与注意**                                               |
| --------------- | ---------- | ------------------------------------------------------------ |
| `<h1>` - `<h6>` | 标题       | `<h1>` 最大，`<h6>` 最小。                                   |
| `<p>`           | 段落       | 自动换行。                                                   |
| `<br>`          | 换行       | **单标签**，没有结束标签 `</br>`。                           |
| `<hr>`          | 水平分割线 | **单标签**。                                                 |
| `<a>`           | 超链接     | `<a href="http://www.baidu.com" target="_blank">点我</a>` **href**: 网址; **target="_blank"**: 新窗口打开。 |
| `<img>`         | 图片       | `<img src="a.jpg" alt="图片描述" width="100">` **src**: 路径; **alt**: 图片加载失败显示的字。 |
| `<ul>` + `<li>` | 无序列表   | 前面是黑点。`<ul><li>第一项</li></ul>`                       |
| `<ol>` + `<li>` | 有序列表   | 前面是数字 1, 2, 3。                                         |
| `<div>`         | 块级容器   | 独占一行，常用于布局。                                       |
| `<span>`        | 行内容器   | 不换行，常用于修饰文字（如变色）。                           |

### 3. 表格 (Table) - 考试必考

结构：`<table>` (表格) -> `<tr>` (行) -> `<td>` (单元格) / `<th>` (表头，自动加粗居中)。

**单元格合并 (重点):**

- **跨列合并 (左右合并)**: `colspan="n"` (n是合并格数)
- **跨行合并 (上下合并)**: `rowspan="n"`

```html
<table border="1"> <tr>
    <th>姓名</th>
    <th>成绩</th>
  </tr>
  <tr>
    <td>张三</td>
    <td rowspan="2">跨行合并(这也占下一行)</td>
  </tr>
  <tr>
    <td>李四</td>
    </tr>
</table>
```

### 4. 表单 (Form) - 数据交互核心

用于向服务器提交数据。核心标签 `<form action="提交地址" method="get/post">`。

**常用控件 (`<input type="...">`):**

- `type="text"`: 文本框 (用户名)
- `type="password"`: 密码框 (输入显示星号)
- `type="radio"`: 单选按钮 (必须设置相同的 **name** 属性才能互斥)
- `type="checkbox"`: 复选框
- `type="submit"`: 提交按钮 (点击触发表单提交)
- `type="reset"`: 重置按钮 (清空表单)
- `type="hidden"`: 隐藏域 (用户看不见，但会提交数据)

**下拉列表 (`<select>`):**
```html
<select name="city">
    <option value="bj">北京</option>
    <option value="sh" selected>上海 (默认选中)</option>
</select>

```

------

## 第二部分：CSS 基础 (样式美化)

### 1. CSS 引入方式

- **行内样式**: `<p style="color:red;">` (优先级最高)
- **内部样式**: 写在 `<head><style> ... </style></head>` 中。
- **外部样式**: `<link rel="stylesheet" href="style.css">` (最推荐)。

### 2. CSS 选择器 (如何选中元素) - 核心考点

| **选择器**     | **符号**     | **语法示例**                 | **说明**                               |
| -------------- | ------------ | ---------------------------- | -------------------------------------- |
| **标签选择器** | 无           | `p { color: red; }`          | 选中页面所有 `<p>` 标签                |
| **类选择器**   | **.** (点)   | `.box { width: 100px; }`     | 选中所有 `class="box"` 的元素 (可重复) |
| **ID选择器**   | **#** (井号) | `#header { height: 50px; }`  | 选中 `id="header"` 的元素 (**ID唯一**) |
| **并集选择器** | **,** (逗号) | `h1, p { color: blue; }`     | h1 和 p 都变蓝                         |
| **后代选择器** | **空格**     | `div p { font-size: 14px; }` | 选中 div 里面所有的 p                  |

### 3. 常用样式属性

- **字体**: `font-size: 16px;` (大小), `font-weight: bold;` (加粗), `font-family: "宋体";`
- **文本**: `color: #FF0000;` (颜色), `text-align: center;` (居中), `text-decoration: none;` (去下划线)。
- **背景**: `background-color: red;` (背景色), `background-image: url('a.jpg');`
- **隐藏**: `display: none;` (消失且不占位), `visibility: hidden;` (消失但占位)。

### 4. 盒子模型 (Box Model)

每个元素都是一个盒子。

- **Content (内容)**: 中间的文字/图片。
- **Padding (内边距)**: 内容到边框的距离 (撑大盒子)。 -> `padding: 10px;`
- **Border (边框)**: 盒子的皮。 -> `border: 1px solid black;` (粗细 样式 颜色)
- **Margin (外边距)**: 盒子与其他元素的距离。 -> `margin: 20px;`
  - *技巧*: `margin: 0 auto;` 可让块级元素水平居中。

------

## 第三部分：HTML DOM (原生 JS 交互)

### 1. 获取元素 (背下来)

- `document.getElementById("id名")`: 返回**一个**元素对象。
- `document.getElementsByName("name名")`: 返回**数组** (NodeList)。
- `document.getElementsByTagName("标签名")`: 返回**数组**。

### 2. 修改元素内容与样式

假设有 `<div id="demo">旧内容</div>`
````JavaScript
var obj = document.getElementById("demo");

// 1. 修改内容
obj.innerHTML = "<h1>新内容</h1>"; // 能解析HTML标签
obj.innerText = "新文本";          // 只能当纯文本显示

// 2. 修改样式 (style.属性名)
// 注意：CSS中的 background-color 变成驼峰式 backgroundColor
obj.style.color = "red";
obj.style.fontSize = "20px";
obj.style.display = "none"; // 隐藏

// 3. 修改属性
obj.setAttribute("class", "newClass");
var val = document.getElementById("username").value; // 获取输入框的值
````


### 3. DOM 事件 (Event)

- `onload`: 页面加载完毕。
- `onclick`: 鼠标点击。
- `onblur`: 失去焦点 (常用于表单校验)。
- `onfocus`: 获得焦点。
- `onchange`: 下拉框或文本内容改变。

------

## 第四部分：jQuery (简化的 JS)

核心口号：`Write Less, Do More`。核心对象：`$`。

### 1. jQuery 基础语法

```js
$(selector).action()
```

- `$`：定义 jQuery。
- `selector`：选择器 (查询 HTML 元素)。
- `action()`：执行对元素的操作。

**入口函数 (防止文档未加载完就执行):**


```JavaScript
$(document).ready(function(){
   // 代码写在这里
});
// 简写:
$(function(){ ... });
```

### 2. jQuery 选择器 (兼容 CSS)

- `$("#test")`: 选取 id="test" 的元素。
- `$(".test")`: 选取 class="test" 的元素。
- `$("p")`: 选取所有 p 元素。
- `$("tr:even")`: 选取偶数行 (索引从0开始，实际是第1,3,5...行)。
- `$("tr:odd")`: 选取奇数行。
- `$("li:eq(2)")`: 选取索引等于 2 的 li (即第3个)。

### 3. jQuery 常用操作

- **内容操作**:

  - `html()` / `html("...")`: 获取/设置 HTML (类似 innerHTML)。
  - `text()` / `text("...")`: 获取/设置文本 (类似 innerText)。
  - `val()` / `val("...")`: 获取/设置表单值 (最常用)。

- **属性/样式**:

  - `attr("href", "http://...")`: 设置属性。
  - `css("color", "red")`: 设置样式。
  - `addClass("blue")` / `removeClass("blue")`: 添加/删除类。

- **显示/隐藏**:

  - `show()` / `hide()` / `toggle()` (切换)。
  - `fadeIn()` (淡入) / `fadeOut()` (淡出)。
  - `slideDown()` (下滑) / `slideUp()` (上滑)。

- **遍历**:



```JavaScript
  $("li").each(function(index, element){
      // index是索引, this 或 element 是当前元素
  });
  ```

------

## 第五部分：JSP 基础 (Java Server Pages)

JSP 本质是 Servlet，用于在 HTML 中嵌入 Java 代码。

### 1. JSP 脚本元素 (三种写法)

考试一定要分清这三个符号：

1. **Scriptlet (脚本小程序)**: `<% Java代码 %>`
   - 里面写普通的 Java 逻辑 (if, for, 变量定义)。
   - *注意*: 这里的变量是**局部变量**。
   - *示例*: `<% int i = 0; %>`
2. **Expression (表达式)**: `<%= 变量或返回值 %>`
   - **作用**: 直接在页面上**输出**内容。
   - *注意*: **没有分号**！等价于 `out.print(...)`。
   - *示例*: `<%= "当前时间:" + new java.util.Date() %>`
3. **Declaration (声明)**: `<%! Java代码 %>`
   - 定义**全局**成员变量或方法。
   - *示例*: `<%! int count = 0; %>`

### 2. JSP 九大内置对象 (Implicit Objects)

不用 new，直接能用的对象。**前四个最重要**。

| **对象名**   | **类型**            | **作用**                                        | **常用方法**                                                 |
| ------------ | ------------------- | ----------------------------------------------- | ------------------------------------------------------------ |
| **request**  | HttpServletRequest  | **请求对象**。获取客户端提交的数据。            | `String v = request.getParameter("name");` (获取表单值) `request.setAttribute("k", v);` (存值转发) |
| **response** | HttpServletResponse | **响应对象**。向客户端发送数据。                | `response.sendRedirect("a.jsp");` (重定向/跳转)              |
| **session**  | HttpSession         | **会话对象**。跨页面保存用户状态 (如登录信息)。 | `session.setAttribute("user", "admin");` `session.getAttribute("user");` |
| **out**      | JspWriter           | **输出对象**。向页面打印内容。                  | `out.print("Hello");`                                        |
| application  | ServletContext      | 全局应用对象，所有用户共享。                    |                                                              |
| pageContext  | PageContext         | 页面上下文，可获取其他8个对象。                 |                                                              |
| config       | ServletConfig       | 配置对象。                                      |                                                              |
| page         | Object              | 当前 JSP 页面本身 (this)。                      |                                                              |
| exception    | Throwable           | 异常对象 (仅在错误页 errorPage 中可用)。        |                                                              |

### 3. JSP 指令 (Directives)

写在页面最顶端，语法 `<%@ 指令名 属性=值 %>`

- **page 指令**: 设置页面属性。



  ```  Java
  <%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" import="java.util.*" %>
  ```

- **include 指令**: 静态包含 (把别的页面代码拷进来)。


  ```Java
  <%@ include file="header.jsp" %>
  ```

- **taglib 指令**: 引入标签库 (如 JSTL)。


  ```  Java
  <%@ taglib prefix="c" uri="[http://java.sun.com/jsp/jstl/core](http://java.sun.com/jsp/jstl/core)" %>
  ```

### 4. 转发 vs 重定向 (经典考题)

- **转发 (Forward)**: `request.getRequestDispatcher("b.jsp").forward(request, response);`
  - 地址栏**不变**。
  - 是一次请求 (request 域数据**共享**)。
  - 发生在服务器内部。
- **重定向 (Redirect)**: `response.sendRedirect("b.jsp");`
  - 地址栏**改变**。
  - 是两次请求 (request 域数据**丢失**)。
  - 客户端重新发起的。

### 5. 中文乱码解决 (万能代码)

在 JSP 或 Servlet 开头加上：

  ```Java
request.setCharacterEncoding("UTF-8"); // 解决接收数据的乱码
response.setContentType("text/html;charset=UTF-8"); // 解决输出到页面的乱码
```

------

## 附录：开卷考试拿分技巧

1. **看清题目环境**: 问的是 CSS 还是 jQuery？比如设置颜色，CSS是 `color:red`，jQuery是 `.css("color","red")`。
2. **分清 ID 和 Class**: ID 是 `#` (唯一)，Class 是 `.` (多个)。
3. **JSP 填空**: 如果看到 `<%= ... %>` 里面千万别加分号；如果问获取表单数据，闭眼写 `request.getParameter("name")`。
4. **JS 找元素**: 记不住复杂的方法就用 `document.getElementById`，这是最稳的。