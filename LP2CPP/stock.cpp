#include <iostream>
#include <string>
#include <algorithm>

void stock_market_expert_system() {
    std::cout << "📈 Welcome to the Stock Market Trading Expert System 📈" << std::endl;
    std::cout << "Please answer the following questions with 'yes' or 'no'.\n" << std::endl;
    
    std::string price_up, high_volume, positive_news, market_bullish, price_down, negative_news;
    
    std::cout << "Is the stock price rising? ";
    std::cin >> price_up;
    std::transform(price_up.begin(), price_up.end(), price_up.begin(), ::tolower);
    
    std::cout << "Is the trading volume higher than usual? ";
    std::cin >> high_volume;
    std::transform(high_volume.begin(), high_volume.end(), high_volume.begin(), ::tolower);
    
    std::cout << "Is there any positive news about the company? ";
    std::cin >> positive_news;
    std::transform(positive_news.begin(), positive_news.end(), positive_news.begin(), ::tolower);
    
    std::cout << "Is the overall market trend bullish? ";
    std::cin >> market_bullish;
    std::transform(market_bullish.begin(), market_bullish.end(), market_bullish.begin(), ::tolower);
    
    std::cout << "Is the stock price falling sharply? ";
    std::cin >> price_down;
    std::transform(price_down.begin(), price_down.end(), price_down.begin(), ::tolower);
    
    std::cout << "Is there any negative news about the company? ";
    std::cin >> negative_news;
    std::transform(negative_news.begin(), negative_news.end(), negative_news.begin(), ::tolower);
    
    std::cout << "\n🧠 Trading Advice:" << std::endl;
    
    if (price_up == "yes" && high_volume == "yes" && positive_news == "yes" && market_bullish == "yes") {
        std::cout << "- Action: STRONG BUY 🛒" << std::endl;
        std::cout << "- Reason: Positive momentum and market support." << std::endl;
    }
    else if (price_up == "yes" && (positive_news == "yes" || market_bullish == "yes")) {
        std::cout << "- Action: BUY ✅" << std::endl;
        std::cout << "- Reason: Stock showing strength, supported by good news or market trend." << std::endl;
    }
    else if (price_down == "yes" && negative_news == "yes") {
        std::cout << "- Action: SELL 🚨" << std::endl;
        std::cout << "- Reason: Price dropping with negative sentiment. Better to exit." << std::endl;
    }
    else if (price_down == "yes" && market_bullish == "no") {
        std::cout << "- Action: SELL or HOLD ⚠️" << std::endl;
        std::cout << "- Reason: Market weak and stock falling. Assess risk tolerance." << std::endl;
    }
    else {
        std::cout << "- Action: HOLD 🤔" << std::endl;
        std::cout << "- Reason: No strong signals. Wait for clearer opportunity." << std::endl;
    }
    
    std::cout << "\n✅ Thank you for using the Stock Market Expert System! Trade wisely!" << std::endl;
}

int main() {
    stock_market_expert_system();
    return 0;
}