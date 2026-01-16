# Web 前端开发全能速查手册 

> **覆盖范围**：HTML5, CSS3, 盒子模型, Flex布局, 移动端适配, JavaScript, HTML DOM, jQuery
> **资料来源**：汇总自上传的13份课程PPT

---

## 第一部分：HTML 核心与文档结构

**核心考点**：Head标签配置、主体标签分类

### 1. 标准文档结构

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"> <title>考试页面</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
    <base href="[http://www.site.com/](http://www.site.com/)" target="_blank"> 
    <link rel="stylesheet" href="style.css"> <script src="script.js"></script>        <style> /* 内部 CSS */ </style>
</head>
<body>
    </body>
</html>
```

### 2. 常用主体标签 (Body)

- **块级元素 (Block)**: `<div>` (布局容器), `<p>` (段落), `<h1>-<h6>` (标题), `<ul><li>` (无序列表), `<ol><li>` (有序列表), `<hr>` (分割线).
  - *特征*: 独占一行，宽度默认100%，可设宽高。
- **行内元素 (Inline)**: `<span>` (文本容器), `<a>` (超链接), `<br>` (换行).
  - *特征*: 不独占一行，宽高由内容撑开，不可设宽高。
- **行内块元素**: `<img>` (图片).

------

## 第二部分：表单 (Forms) 与 表格 (Tables)

**核心考点**：表单控件类型、表格合并

### 1. 表单 `<form>`

用于收集用户数据。


```HTML
<form action="submit.jsp" method="post" enctype="multipart/form-data">
    用户: <input type="text" name="user" value="默认值" placeholder="提示文字" required>
    密码: <input type="password" name="pwd">
    
    性别: <input type="radio" name="sex" value="m" checked>男
          <input type="radio" name="sex" value="f">女
    爱好: <input type="checkbox" name="hobby" value="code">编程
    
    城市: <select name="city">
            <option value="bj">北京</option>
            <option value="sh" selected>上海</option>
          </select>
          
    邮箱: <input type="email">
    数字: <input type="number" min="0" max="100" step="5">
    日期: <input type="date">
    
    <input type="submit" value="提交">
    <input type="reset" value="清空">
    <input type="file" name="upload"> </form>
```

### 2. 表格 `<table>`

- **结构**: `<table>` > `tr` (行) > `td` (单元格) / `th` (加粗表头).
- **合并单元格 (重点)**:
  - `rowspan="2"`: **跨行合并** (纵向吃掉下方的格子).
  - `colspan="2"`: **跨列合并** (横向吃掉右边的格子).

------

## 第三部分：CSS 基础与盒子模型

**核心考点**：选择器权重、盒子尺寸计算

### 1. CSS 选择器

| **选择器**     | **符号/示例** | **说明**                     |
| -------------- | ------------- | ---------------------------- |
| **ID选择器**   | `#nav`        | 权重高，ID唯一               |
| **类选择器**   | `.box`        | 最常用，可重复               |
| **标签选择器** | `div`         | 选中所有该标签               |
| **后代选择器** | `div p`       | 选中 div 内的所有 p (含孙子) |
| **子代选择器** | `div > p`     | 选中 div 的**直接**子元素    |
| **并集选择器** | `h1, p`       | 多个标签应用同一样式         |
| **伪类**       | `a:hover`     | 鼠标悬停状态                 |

### 2. 框模型 (Box Model)

元素在页面中占据的总宽度计算：

总宽度 = width + padding(左右) + border(左右) + margin(左右)

- **Content**: 内容区域 (`width`, `height`).
- **Padding**: 内边距 (内容到边框的距离)。`padding: 10px 20px;` (上下10，左右20).
- **Border**: 边框。`border: 1px solid red;`.
- **Margin**: 外边距 (盒子间的距离)。
  - *技巧*: `margin: 0 auto;` 让块级元素水平居中。
  - *塌陷*: 垂直方向相邻元素的 margin 会取最大值而非相加。

------

## 第四部分：CSS 布局 (Position & Flex)

**核心考点**：定位参考点、Flex主轴交叉轴

### 1. 定位 (Position)

- **`static`**: 默认值，文档流。
- **`relative` (相对定位)**:
  - 参考点：**自己原来的位置**。
  - 特点：**占有原位置** (不脱离文档流)。
- **`absolute` (绝对定位)**:
  - 参考点：**最近的非 static 祖先** (通常父级设 relative，子级设 absolute -> "子绝父相")。
  - 特点：**脱离文档流** (不占位，浮在上方)。
- **`fixed` (固定定位)**:
  - 参考点：**浏览器窗口**。
  - 特点：页面滚动时元素**不动**。

### 2. Flex 布局 (弹性盒子)

父容器属性: `.container { display: flex; }`

- **`flex-direction`**: `row` (横向，默认) | `column` (纵向).
- **`justify-content` (主轴/水平对齐)**:
  - `flex-start` (左) | `center` (中) | `space-between` (两端对齐) | `space-around` (环绕).
- **`align-items` (侧轴/垂直对齐)**:
  - `stretch` (拉伸，默认) | `center` (居中).
- **`flex-wrap`**: `wrap` (换行).

子项目属性:

- **`flex: 1;`**: 均分剩余空间 (自适应宽度).

------

## 第五部分：移动端响应式布局

**核心考点**：Viewport、Rem适配、媒体查询

### 1. 核心设置

- **Viewport**: `<meta name="viewport" content="width=device-width, initial-scale=1.0">` (必须写).

- **Media Query (媒体查询)**:

  ```CSS
  /* 屏幕宽度小于 768px 时生效 */
  @media screen and (max-width: 768px) {
      body { background: pink; }
      .pc-nav { display: none; }
  }
  ```

### 2. 适配单位

- **px**: 绝对单位。
- **%**: 百分比。
- **rem**: 相对于 **html根元素** 的 `font-size`。
  - *适配原理*: JS (如 flexible.js) 动态根据屏幕宽修改 `html` 的 `font-size`，元素用 `rem` 做单位。
  - *计算*: 元素尺寸 / html字号 = rem值。
- **vw / vh**: 视口宽/高的 1% (100vw = 满屏宽)。

------

## 第六部分：JavaScript 基础

**核心考点**：变量、函数、输出

### 1. 基础语法

- **输出**: `alert("弹窗")`, `console.log("控制台")`, `document.write("页面")`.

- **变量**: `var name = "Tom";` (弱类型).

- **函数**:

  ```JavaScript
  function add(a, b) {
      return a + b;
  }
  ```

### 2. 事件 (Events)

- `onclick`: 点击。
- `onload`: 页面/图片加载完毕。
- `onchange`: 表单内容改变 (常用于 select).
- `onmouseover / onmouseout`: 鼠标移入/移出。

------

## 第七部分：HTML DOM 操作

**核心考点**：获取元素、修改内容/样式

### 1. 查找元素 (背诵)

- `document.getElementById("id")`: 返回**一个**对象。
- `document.getElementsByTagName("p")`: 返回对象**集合**(数组)。
- `document.getElementsByClassName("cls")`: 返回对象**集合**。

### 2. 修改 DOM

- **内容**:
  - `obj.innerHTML = "<b>粗体</b>";` (解析HTML).
  - `obj.innerText = "文本";` (纯文本).
- **样式**:
  - `obj.style.color = "red";`
  - `obj.style.display = "none";` (隐藏).
  - `obj.style.fontSize = "20px";` (注意驼峰写法).
- **属性**:
  - `obj.src = "pic.jpg";`
  - `obj.setAttribute("class", "active");`

------

## 第八部分：jQuery

核心考点：选择器、链式操作

核心: Write Less, Do More. 符号: $

### 1. 入口函数

```JavaScript
// 确保页面加载完再执行，等同于 window.onload
$(function(){
    // 代码写这里
});
```

### 2. jQuery 选择器 (兼容CSS)

- `$("#id")`: ID选择器.
- `$(".class")`: 类选择器.
- `$("div p")`: 祖先 后代.
- `$("ul li:eq(0)")`: 第1个 li.
- `$("tr:even")`: 偶数行 (用于隔行变色).

### 3. 常用方法

- **样式**: `.css("width", "100px")`, `.addClass("active")`, `.removeClass("active")`.

- **内容**: `.html()`, `.text()`, `.val()` (获取/设置表单值).

- **属性**: `.attr("href", "url")`.

- **DOM操作**:

  - `.append()`: 内部追加.
  - `.remove()`: 删除.
  - `.empty()`: 清空内容.

- **动画**: `.show()`, `.hide()`, `.toggle()`, `.fadeIn()`, `.slideDown()`.

- **遍历**:

  ```JavaScript
  $("li").each(function(index, element){
      console.log(index);
  });
  ```