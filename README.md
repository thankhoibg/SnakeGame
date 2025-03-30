# Snake_Game

# Introduction
+ Họ và tên : Thân Đăng Khôi - K69I-IT5 - UET
+ Mã sinh viên : 24020185
+ Bài tập lớn : SnakeGame (2425II_INT2215_4 - Lập trình nâng cao)

# Description
***Game description and instruction***

+ Đây là trò chơi rắn săn mồi hay nhất từ trước đến nay với nhiều tính năng hay, vượt trội. Game tổng cộng có 2 chế độ chơi, người chơi chọn Play Game và thao tác ở màn hình chính: 
   + Chế độ 1: Đây là chế độ một người chơi, là một chế độ rắn săn mồi cơ bản như chúng ta đã biết.
   + Chế độ 2 : ***AI*** đây là chế độ với AI, người chơi được AI hỗ trợ, tìm ra đường đi gần như tối ưu.
+ Game có hỗ trợ mọi tính năng cần thiết :
   + Âm nhạc : Trong màn hình chính, người chơi click chuột vào màn biểu tượng âm nhạc để chọn cho mình âm thanh phù hợp.
   + Dừng game khi chơi : Người chơi nhấn phím "P", khi đó game sẽ dừng và mở ra một tool bar để người chơi có thể chọn những tác vụ mình cần.
   + Các tác vụ cần thiết khác game cũng đã được tích hợp.
 
### Control
   + Up Arrow | W : Di chuyển lên
   + Down Arrow | S : Di chuyển xuống
   + Left Arrow | A : Di chuyển sang trái
   + Right Arrow | D : Di chuyển sang phải

# Demo
   [Link Demo](https://www.youtube.com/)


# Các kỹ thuật sử dụng
   + Thư viện SDL2.0
   + Có thể lưu lại điểm số cao nhất nhờ đọc ghi file
   + Dùng kiến thức toán học để thực hiện phép bo cong thân rắn
   + Khả năng tổ chức code, nạp chồng toán tử, lập trình hướng đối tượng như : tạo các đối tượng : rắn, nhiều loại quả,.... 
   + Các kiến thức ngoài chương trình : Toán rời rạc, Advance Algorithm như: BFS, DFS, tạo thành phần liên thông, Greedy, xử lý sai số trong hệ tọa độ bằng kỹ thuật đơn giản, dùng các stl như vector, deque...
   + Xử lý thao tác người dùng với trò chơi như thao tác với chuột và bàn phím
   + Tạo menu và các phím thao tác trong game

### Nguồn tham khảo
   + ***Về Syntax của SDL và cách hoạt động của chúng :*** Em học trên thư viện của SDL.
   + ***Về đồ họa Game :*** Một vài hình ảnh trong game em có lấy từ Google
   + ***Về âm thanh :*** Em tìm kiếm trên Google

# Conclusion
  ## Điều tâm đắc
   + Dự án này là tự tay em làm mọi phần trong thời gian trung bình, không sao chép từ bất cứ ai hay bất cứ nguồn nào
   + Em đã học được rất nhiều điều sau dự án này, đặc biệt là khả năng code của bản thân. Nhờ phải quản lý một khối công việc lớn cũng như tổ chức code sao cho hợp lý em đã nâng cao khả năng lập trình rất nhiều.
   + Dự án này cũng đã giúp em cải thiện khả năng đọc hiểu Tiếng Anh (các câu lệnh mới từ thư viện SDL và cách dùng của chúng) cũng như tăng khả năng làm việc đường dài của bản thân.
 ## Điểm hạn chế
   + Điểm hạn chế duy nhất của game theo em là đồ họa vẫn chưa được tốt nhất so với khả năng của chính em
 ## Hướng phát triển 
   + Tạo thêm nhiều loại quả, thêm chế độ chơi Player VS AI
      + Tạo 2 bảng cho người chơi và AI so tài. Hoặc tạo 1 bảng để người chơi và AI tranh food.
      + Tạo thêm các màn chơi có chướng ngại vật.
      + Hướng phát triển em nghĩ là hay nhất: Ta sẽ tạo thêm cho rắn AI những điều kiện khi ăn quả. Thay vì suy nghĩ đơn giản là thêm các loại quả, ta sẽ có những điều kiện để  rắn có thể đến được ô ăn quả táo. Một trong những hướng đó chính là chỉ cho phép rắn ăn quả nếu đi đúng điều kiện ta cho phép, có thể là vào ở một hướng và ra ở một hướng. Khi đó ta chỉ cần thêm một trạng thái, hay **bitmask** vào trong hàm BFS của chúng ta (vì bản chất BFS cũng chỉ là thuật toán **quy hoạch động**), đây cũng có thể là một chế độ tiềm năng.
   + Tạo thêm cho AI suy nghĩ cũng như tạo thêm độ khó của AI Mode
 ## Kết luận
   + Sau dự án này, em thật sự cảm ơn các thầy cô, thầy **Kiều Hải Đăng** cũng như các anh/chị mentor vì đã giúp em có được một trải nghiệm chưa từng có, cải thiện rất nhiều cũng như bù đắp những thiếu sót trong các kỹ năng của em. Em xin chân thành cảm ơn
